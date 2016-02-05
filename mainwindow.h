#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QStandardItemModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QStandardItemModel* model, QWidget *parent = 0);
    ~MainWindow();

signals:
    void startServer();

public slots:
    void status(QString);

private slots:
    void on_close_conn_clicked();
    void on_close_all_clicked();
    void on_start_server_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *_model;

};

#endif // MAINWINDOW_H
