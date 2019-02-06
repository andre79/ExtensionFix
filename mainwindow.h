#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void populateCheckBox();
private slots:
    void on_pushButton_clicked();

    void on_mainListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_mainListWidget_itemActivated(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
