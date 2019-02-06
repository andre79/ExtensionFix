#include <QCoreApplication>
#include <iostream>
#include <experimental/filesystem>
#include<stdio.h>
#include <fstream>

using namespace std;
namespace fs = std::experimental::filesystem::v1;
#include <fstream>      // std::ifstream

void rep(string &initialString, string whatToReplace, string withWhat)
{
    size_t rpos=initialString.find(whatToReplace);
    if (rpos!=string::npos)
        initialString.replace(initialString.begin()+rpos, initialString.begin()+rpos+whatToReplace.length(), withWhat);
}

bool endsWith(const string& a, const string& b)
{
    if (b.size() > a.size()) return false;
    return std::equal(a.begin() + a.size() - b.size(), a.end(), b.begin());
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<std::string> scenarioNames;
    int size = 4;
    vector<std::string> wrongSerieNames = {"ETP.srs", "PRECIPITATION.srs", "RUNOFF_IN_NAT.srs", "RESOP_DEMAND.srs"};
    vector<std::string> correctSerieNames = {"ETP.007.srs", "PRECIPITATION.007.srs", "RUNOFF_IN_NAT.005.srs", "RESOP_DEMAND.005.srs"};
    vector<std::string> unitOfSerie = {"# Unidade: mm", "# Unidade: mm", "# Unidade: m³/s", "# Unidade: m³/s"};

    std::string url = "C:/SigaProjectsFile/leste";
    std::string url9004 = url + "/9004/";

    //Abre arquivo url9004+RESOP_SCENARIOS_NAMES.vctr
    std::ifstream input(url9004+"RESOP_SCENARIOS_NAMES.vctr");
    for(std::string line; getline(input, line); )
    {
        scenarioNames.push_back(url9004+line);
    }

    //Para cada elemento
    for (const auto & elementFolder : fs::directory_iterator(url9004))
    {
        //std::cout << elementFolder.path() << std::endl;

        //Se for o nome de um cenário, deve pular
        bool cont = true;
        for (auto &scen: scenarioNames)
        {
            if (scen.compare(elementFolder.path().string()) == 0)
            {
                cont = false;
                break;
            }
        }
        if (!cont) continue;

        if (!fs::is_directory(elementFolder.path())) continue;

        //std::cout << elementFolder.path() << std::endl;

        //Para cada scenario
        for (const auto & scenarioFolder : fs::directory_iterator(elementFolder.path()))
        {
           // std::cout << scenarioFolder.path() << std::endl;

            //Para cada modelo
            for (const auto & modelFolder : fs::directory_iterator(scenarioFolder.path()))
            {
                //std::cout << modelFolder.path() << std::endl;

                std::string filename;
                std::string filename_2;
                for (const auto & file : fs::directory_iterator(modelFolder.path()))
                {
                    //Se o arquivo termina com .srs
                    filename = file.path().string();
                    //if (endsWith(filename, ".srs")) std::cout << filename << std::endl;

                    for (int index = 0; index < size; ++index)
                    {
                        //if (endsWith(filename, "RESOP_DEMAND.srs"))
                        if (endsWith(filename, wrongSerieNames[index]))
                        {
                            /*std::cout << filename << std::endl;
                            filename_2 = filename;
                            //rep(filename, "RESOP_DEMAND.srs", "RESOP_DEMAND.005.srs");
                            rep(filename, wrongSerieNames[index], correctSerieNames[index]);
                            std::cout << filename << std::endl;
                            std::rename(filename_2.c_str(), (filename+"temp").c_str());*/

                            filename_2 = filename;
                            rep(filename, wrongSerieNames[index], correctSerieNames[index]);

                            int linePos = 0;
                            //novo nome: filename
                            std::ifstream infile(filename_2);
                            std::string line;
                            std::string fileContent;
                            while (std::getline(infile, line))
                            {
                                if (linePos != 1)
                                    fileContent += line+"\n";
                                else
                                    fileContent += unitOfSerie[index]+"\n";
                                //std::cout << line << std::endl;
                                linePos++;
                            }
                            infile.close();
                            //Deve salvar o conteudo como um arquivo filename
                            ofstream newFile;
                            newFile.open (filename);
                            newFile << fileContent;
                            newFile.flush();
                            newFile.close();

                            //Deletar o arquivo
                            std::remove(filename_2.c_str());
                        }
                    }
                }
            }
        }
    }

    return a.exec();
}
