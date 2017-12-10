#include "connectdb.h"
#include "ui_connectdb.h"
#include<QMessageBox>
#include<QDesktopServices>
#include<QUrl>


connectDb::connectDb(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::connectDb)
{
    ui->setupUi(this);
    if (!conOpen())
         qDebug() << "Error: connection with database fail";
    else
        qDebug() << "Database: connection ok";
}

connectDb::~connectDb()
{
    delete ui;
}

void connectDb::on_pButtonAddherb_clicked() // adding records
{
    QString cname,sname,family,use;
    cname=ui->lineEditCname->text();
    sname=ui->lineEditSname->text();
    family=ui->lineEditFamily->text();
    use=ui->lineEditUse->text();

   if(!conOpen()){
        qDebug() << "ohh noo database fail";
   return;
       }

   conOpen();
   QSqlQuery qry;
   qry.prepare("insert into hinfo (common_name,scientific_name,family,use) values ('"+cname+"','"+sname+"','"+family+"','"+use+"')");
   if(qry.exec())
   {
     QMessageBox::critical(this,tr("Save"),tr("Saved"));
     conCose();
     ui->lineEditCname->setText(""); // clear input boxes
      ui->lineEditSname->setText("");
       ui->lineEditFamily->setText("");
        ui->lineEditUse->setText("");
   }
   else
   {
       QMessageBox::critical(this,tr("Error"),qry.lastError().text());
   }

}

void connectDb::on_pButtonUpdate_clicked() //update records
{
    QString cname,sname,family,use;
    cname=ui->lineEditCname->text();
    sname=ui->lineEditSname->text();
    family=ui->lineEditFamily->text();
    use=ui->lineEditUse->text();

   if(!conOpen()){
        qDebug() << "ohh noo database failed to open";
   return;
       }

   conOpen();
   QSqlQuery qry;
   qry.prepare("update hinfo set common_name='"+cname+"',scientific_name='"+sname+"',family='"+family+"',use='"+use+"'where scientific_name='"+sname+"'");
   if(qry.exec())
   {
     QMessageBox::critical(this,tr("Edit"),tr("Updated"));
     conCose();
     ui->lineEditCname->setText("");
      ui->lineEditSname->setText("");
       ui->lineEditFamily->setText("");
        ui->lineEditUse->setText("");
   }
   else
   {
       QMessageBox::critical(this,tr("Error"),qry.lastError().text());
   }
}

void connectDb::on_pButtonDelete_clicked() //delete records
{
    QString sname;
    //scientific_name is the primary key of the data base so it will use as a key to delete records

    sname=ui->lineEditSname->text();


   if(!conOpen()){
        qDebug() << "ohh noo database failed to open";
   return;
       }

   conOpen();
   QSqlQuery qry;
   qry.prepare("delete from hinfo where scientific_name='"+sname+"'");
   if(qry.exec())
   {
     QMessageBox::critical(this,tr("Delete"),tr("Deleted"));
     conCose();
     ui->lineEditCname->setText("");
      ui->lineEditSname->setText("");
       ui->lineEditFamily->setText("");
        ui->lineEditUse->setText("");
   }
   else
   {
       QMessageBox::critical(this,tr("Error"),qry.lastError().text());
   }
}




void connectDb::on_pButtonSearch_clicked() //search records
{
    QString sname;
        sname=ui->lineEditSearch->text();
       QSqlQueryModel* model =new QSqlQueryModel();
        conOpen();

       QSqlQuery* qry=new QSqlQuery(mydb);

       qry->prepare("select * from hinfo where scientific_name='"+sname+"'");
       qry->exec();
       model->setQuery(*qry);
       ui->treeViewSearch->setModel(model);
        conCose();
        ui->lineEditSearch->setText("");

        qDebug() << (model->rowCount());

}

void connectDb::on_tabWidget_tabBarClicked(int index)
{
    //sname=ui->lineEditSname->text();
   QSqlQueryModel* model =new QSqlQueryModel();
    conOpen();

   QSqlQuery* qry=new QSqlQuery(mydb);

   qry->prepare("select * from hinfo");
   qry->exec();
   model->setQuery(*qry);
   ui->treeView->setModel(model);
    conCose();

    qDebug() << (model->rowCount());
}

void connectDb::on_pushButton_clicked() //web searching
{
QString webUrl="https://www.google.com";
QDesktopServices::openUrl(QUrl(webUrl));
}
