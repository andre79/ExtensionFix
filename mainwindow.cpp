#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    populateCheckBox();
    populateNodeCheckBox("Demand");
    populateSelectSerieErrorCheckBox("Error");
    //this->showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void  MainWindow::populateCheckBox()
{

    for(int i = 0; i < 10; ++i)
    {
        ui->mainListWidget->addItem("Novo " + QString::number(i));
    }

    QListWidgetItem* item = 0;

    for(int i = 0; i < ui->mainListWidget->count(); ++i)
    {
        item = ui->mainListWidget->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
    }
}

void  MainWindow::populateNodeCheckBox(QString nodeType)
{

    for(int i = 0; i < 10; ++i)
    {
        ui->listWidgetDemand->addItem(nodeType + " " + QString::number(i));
    }

    QListWidgetItem* item = 0;

    for(int i = 0; i < ui->listWidgetDemand->count(); ++i)
    {
        item = ui->listWidgetDemand->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
    }
}

void  MainWindow::populateSelectSerieErrorCheckBox(QString nodeType)
{

    ui->listWidgetDemandError->addItem("RESOP_DEMAND");
    ui->listWidgetDemandError->addItem("RUNOFF_IN_NAT");

    QListWidgetItem* item = 0;

    for(int i = 0; i < ui->listWidgetDemandError->count(); ++i)
    {
        item = ui->listWidgetDemandError->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
    }
}

void MainWindow::on_pushButton_clicked()
{
    int a = 1;
}

void MainWindow::on_mainListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    int a = 1;
}

void MainWindow::on_mainListWidget_itemActivated(QListWidgetItem *item)
{
    QString a = item->text();
}
