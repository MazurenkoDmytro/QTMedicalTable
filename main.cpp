#include "mainwindow.h"
#include "record.h"
#include <QTextStream>
#include <QApplication>
#include <QTableWidget>
#include <QMessageBox>
#include <QFile>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Record r;
      r.getYear()   ;
    w.show();
    return a.exec();
}
