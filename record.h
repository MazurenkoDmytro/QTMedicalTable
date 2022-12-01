#ifndef RECORD_H
#define RECORD_H

#include <QString>
#include <QTextStream>

class Record{
private:
    int num;
    QString surname;
    QString name;
    int year;
    QString sex;
    double t;
    int gemoglobin;
public:
    Record();
    //Record(const Record&) noexcept;
    Record(int, QString, QString, int,QString, double, int);
    int getNum (){return num;};
    QString getSurname (){return surname;};
    QString getName(){return name;};
    int getYear (){return year;};
    QString getSex(){return sex;};
    double getT(){return t;};
    int getGemoglobin(){return gemoglobin;};
    void setNum(int);
    void setSurname(QString);
    void setName(QString);
    void setYear(int);
    void setSex(QString);
    void setT(double);
    void setGemoglobin(int);
    friend QTextStream & operator << (QTextStream & stream, const Record &r);
    friend QTextStream & operator >> (QTextStream & stream, Record &r);
    friend bool operator== (const Record &r1, const Record &r2);
    friend bool operator!= (const Record &r1, const Record &r2);


};

#endif // RECORD_H
