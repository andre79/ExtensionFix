#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    populateCheckBox();

    this->showMaximized();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void  MainWindow::populateCheckBox(){

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
