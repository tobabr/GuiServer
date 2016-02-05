#include <QStandardItemModel>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QStandardItemModel* model, QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), _model(model)
{
    ui->setupUi(this);
    ui->treeView->setModel(_model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::status(QString message)
{
    ui->statusBar->showMessage(message);
}

void MainWindow::on_close_conn_clicked()
{

}

void MainWindow::on_close_all_clicked()
{

}

void MainWindow::on_start_server_clicked()
{
    emit startServer();
}
