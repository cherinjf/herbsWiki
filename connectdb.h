#ifndef CONNECTDB_H
#define CONNECTDB_H

#include <QMainWindow>
#include <QWidget>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>

namespace Ui {
class connectDb;
}

class connectDb : public QMainWindow
{
    Q_OBJECT
public:
    //mydb is my database name and this is the open and close connection functions for further usage
    QSqlDatabase mydb;
    void conCose()//closing connection function
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool conOpen()//opening onnection function
    {
        mydb=QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/Asus/Documents/herbsWiki/herbs.db");
        if (!mydb.open()){
            qDebug() << "Error: connection with database fail please input right path and turn '\' to '/'";
            return false;
        }
        else{
            qDebug() << "Database: connection ok";
            return true;}
    }


public:
    explicit connectDb(QWidget *parent = 0);
    ~connectDb();

private slots:
    void on_pButtonAddherb_clicked();

    void on_pButtonUpdate_clicked();

    void on_pButtonDelete_clicked();

    //void on_tabWidget_tabBarClicked(int index);

    //void on_pushButton_clicked();

    void on_pButtonSearch_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_pushButton_clicked();

private:
    Ui::connectDb *ui;
};

#endif // CONNECTDB_H
