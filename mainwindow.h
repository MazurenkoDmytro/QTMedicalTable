#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <record.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void SelectWomenWithIncreasedGemoglobin();
    void on_save_clicked();
    void on_add_clicked();
    void LoadFromFile();
    void YoungestMan();
    void Old();
    void SameName();
    void greeting();
    void Merge(QVector<Record> *, int, int);
    void MergeSort(QVector<Record>*, int, int);
    void sort_click();
private:
   QVector<Record> *vec ;
    Ui::MainWindow *ui;
    Record *r;


};
#endif // MAINWINDOW_H
