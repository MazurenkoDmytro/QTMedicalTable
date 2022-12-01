#include "mainwindow.h"
#include "qmessagebox.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <Windows.h>
#include <QCoreApplication>
#include <QTimer>
#include <QDate>

QString const fname = "file.txt";
QFile file(fname);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("MedicalTable");
    r = new Record();
    vec = new QVector<Record>();
    LoadFromFile();

}
void MainWindow::LoadFromFile(){
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    vec->clear();
    QTextStream out(&file);
    if (!file.open(QFile::ReadOnly))
        return;
   while(!out.atEnd()){
          out>>*r;
          ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
          ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(QString::number(r->getNum())));
          ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(r->getSurname()));
          ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(r->getName()));
          ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, new QTableWidgetItem(QString::number(r->getYear())));
          ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 4, new QTableWidgetItem(r->getSex()));
          ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 5, new QTableWidgetItem(QString::number(r->getT())));
          ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 6, new QTableWidgetItem(QString::number(r->getGemoglobin())));
          vec->push_back(*r);
          out.readLine();

    }
file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_add_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
}
void MainWindow::MergeSort(QVector<Record> *vec, int first, int last) {

  if (first < last) {
    MergeSort(vec, first, (first + last) / 2);  //сортировка левой части
    MergeSort(vec, (first + last) / 2 + 1, last);  //сортировка правой части
    Merge(vec, first, last);  //слияние двух частей

  }
 }


  void MainWindow::Merge(QVector<Record> *vec, int first, int last){
      int  middle, start, final, j;

      QVector<Record> v;
      middle = (first + last) / 2;  //вычисление среднего элемента
      start = first;                //начало левой части
      final = middle + 1;           //начало правой части
      for (j = first; j <= last; j++)  //выполнять от начала до конца
        if ((start <= middle) && ((final > last) || (vec->value(start).getT() < vec->value(final).getT()))) {

          v.push_back(vec->value(start));
         //  qDebug()<<v.value(j).getT();
          start++;
        } else {
           v.push_back(vec->value(final)) ;
          final++;
        }
      //возвращение результата в вектор
      for (j = first; j <= last; j++){
        vec->push_back(v.value(j));}


  }
  void MainWindow::sort_click(){ //завдання 1
      qDebug()<<vec->indexOf(vec->first());
      qDebug()<<vec->lastIndexOf(vec->last());
      MergeSort(vec,0,19);

      ui->tableWidget->clearContents();
      ui->tableWidget->setRowCount(0);
      vec->value(1).setT(40);
      for(int i=0;i<vec->length();i++){
          ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
          ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(QString::number(vec->value(i).getNum())));
          ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(vec->value(i).getSurname()));
          ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(vec->value(i).getName()));
          ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, new QTableWidgetItem(QString::number(vec->value(i).getYear())));
          ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 4, new QTableWidgetItem(vec->value(i).getSex()));
          ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 5, new QTableWidgetItem(QString::number(vec->value(i).getT())));
          ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 6, new QTableWidgetItem(QString::number(vec->value(i).getGemoglobin())));
      }

  }
void MainWindow::greeting(){ //завдання 6
    for(int i=0;i<ui->tableWidget->rowCount();i++){
        for(int j=0;j<ui->tableWidget->columnCount();j++){
            if(ui->tableWidget->item(i,j) ==0 ){
                ui->tableWidget->removeRow(i);
                i--;
                break;
            }
        }

    }

    for(int i=0;i<ui->tableWidget->rowCount();i++){
        ui->label_3->setText("Вітання");
        if (QDate::currentDate().year()-ui->tableWidget->item(i,3)->text().toInt() <30 && ui->tableWidget->item(i,5)->text().toDouble()==36.6){

            QMessageBox msgBox;
            msgBox.setWindowTitle("Вітання!");
            msgBox.setText(ui->tableWidget->item(i,1)->text()+" - так триматись!");
            msgBox.exec();
        }
    }

}
void MainWindow::SameName(){//Завдання 5

     QVector<Record> *vecName = new  QVector<Record>();
     QVector<Record> vecMain = *vec;

    for(int i=0;i<ui->tableWidget->rowCount();i++){
        for(int j=0;j<ui->tableWidget->columnCount();j++){
            if(ui->tableWidget->item(i,j) ==0 ){
                ui->tableWidget->removeRow(i);
                i--;
                break;
            }
        }
        if(ui->tableWidget->item(i,4)->text()!="Жінка" || ui->tableWidget->item(i,6)->text().toInt()<120 || ui->tableWidget->item(i,6)->text().toInt()>180  ){
           ui->tableWidget->removeRow(i);
           i--;
       }
    }
    for(int i=0;i<ui->tableWidget->rowCount();i++){
        for (int k=0; k<ui->tableWidget->rowCount(); k++){
            if( ui->tableWidget->item(i,2)->text()== ui->tableWidget->item(k,2)->text() && k!=i){
                vecName->push_back(vecMain.at(i));
                qDebug()<<vecName->value(i).getName();
                break;
            }

        }
    }

    for(int i=0;i<ui->tableWidget->rowCount();i++){
        Record max_age = vecName->value(i);
        Record temp ;
         for(int k=0;k<ui->tableWidget->rowCount();k++){
             if(vecName->value(i).getName()==vecName->value(k).getName()){
                  if (vecName->value(k).getYear()<max_age.getYear()){
                      temp = vecName->value(k);
                      vecName->remove(i);
                      vecMain.remove(i);
                            ui->tableWidget->removeRow(i);
                            max_age=temp;
                        }
                  else if (vecName->value(k).getYear()>max_age.getYear()){
                            ui->tableWidget->removeRow(k);
                            vecName->remove(k);
                             vecMain.remove(k);
                             k--;
                           // i--;
                        }
              }


          }
    }

    ui->label_3->setText("Найстарші жінки з однаковим ім'ям і нормальним показником гемоглобіну");
  delete vecName;
};
void MainWindow::Old(){ //Завдання 4
    for(int i=0;i<ui->tableWidget->rowCount();i++){
        for(int j=0;j<ui->tableWidget->columnCount();j++){
            if(ui->tableWidget->item(i,j) ==0 ){
                ui->tableWidget->removeRow(i);
                i--;
                break;
            }
        }

    }
    for(int i=0;i<ui->tableWidget->rowCount();i++){
        if (QDate::currentDate().year()-ui->tableWidget->item(i,3)->text().toInt() <60 || ui->tableWidget->item(i,5)->text().toDouble()<=36.6 || ui->tableWidget->item(i,6)->text().toInt()>=120 ){
            ui->tableWidget->removeRow(i);
            i--;
        }
    }
    ui->label_3->setText("Люди старші за 60 з підвищеною температурою та пониженим гемоглобіном");
};

void MainWindow::YoungestMan(){ //завдання 3

    for(int i=1;i<ui->tableWidget->rowCount();i++){

      for(int j=0;j<ui->tableWidget->columnCount();j++){
            if(ui->tableWidget->item(i,j) ==0 ){
               ui->tableWidget->removeRow(i);
               i--;
               break;
            }
        }

    }
    for(int i=1;i<ui->tableWidget->rowCount();i++){
    QTableWidgetItem min_age; *(ui->tableWidget->item(0,3));
    QTableWidgetItem* temp;
      if (ui->tableWidget->item(i,4)->text()!="Чоловік" || ui->tableWidget->item(i,5)->text().toDouble()!=36.6 || ui->tableWidget->item(i,6)->text().toInt()>=120 ){
          ui->tableWidget->removeRow(i);
          i--;
      }
      else if (ui->tableWidget->item(i,3)->text().toInt()>min_age.text().toInt()){
          temp = ui->tableWidget->item(i,3);
          ui->tableWidget->removeRow(--i);
          min_age=*temp;
      }
      else if (ui->tableWidget->item(i,3)->text().toInt()<min_age.text().toInt()){
          ui->tableWidget->removeRow(i);
          i--;
      }
    }
   ui->label_3->setText("Наймолодший чоловік(и) з нормальною t та зниженим показником гемоглобіну");

};

void MainWindow::SelectWomenWithIncreasedGemoglobin(){ //Завдання №2
    for(int i=0;i<ui->tableWidget->rowCount();i++){
            if(ui->tableWidget->item(i,4)==0 || ui->tableWidget->item(i,6)==0 || ui->tableWidget->item(i,4)->text()!="Жінка" || ui->tableWidget->item(i,6)->text().toInt()<=180){
               ui->tableWidget->removeRow(i);
               i--;
        }
    }
    ui->label_3->setText("Записи жінок з підвищеним гемоглобіном");
}

void MainWindow::on_save_clicked()
{

    if(!file.open(QFile::WriteOnly))
       { return;}
    QTextStream in(&file);


      for(int j=0;j<ui->tableWidget->rowCount();j++){
    bool flag = true;
         for(int i=0;i<ui->tableWidget->columnCount();i++){

             if(ui->tableWidget->item(j,i)==0){
                 ui->tableWidget->removeRow(j);
                    j--;
                flag = false;
                break;

             }

         }
          if (flag)  {
                r->setNum(ui->tableWidget->item(j,0)->text().toInt());
                 r->setSurname(ui->tableWidget->item(j,1)->text());
                 r->setName(ui->tableWidget->item(j,2)->text());
                 r->setYear(ui->tableWidget->item(j,3)->text().toInt());
                 r->setSex(ui->tableWidget->item(j,4)->text());
                 r->setT( ui->tableWidget->item(j,5)->text().toDouble());
                 r->setGemoglobin(ui->tableWidget->item(j,6)->text().toInt());
                 vec->push_back(*r);
                   in<<(*r);
                 file.flush();
          }
           else {

              flag=true;

          }
    }
      ui->label->setStyleSheet("QLabel {  color : green;}");
      ui->label->setText("Дані збережено." );
      ui->label_2->setStyleSheet("QLabel {  color : red;}");
      ui->label_2->setText("Невірно заповнені та порожні рядки видалено!" );
      ui->label->setVisible(true);
      ui->label_2->setVisible(true);
      QTimer::singleShot(3000, ui->label ,&QLabel::hide);
      QTimer::singleShot(3000, ui->label_2, &QLabel::hide);
      file.close();




}
