#include "record.h"

void Record::setNum(int num){
    this->num=num;
};
void Record::setSurname(QString surname){
    this->surname=surname;
};
void Record::setName(QString name){
    this->name=name;
};
void Record::setYear(int year){
    this->year=year;
};
void Record::setSex(QString sex){
    this->sex=sex;
};

void Record::setT(double t){
    this->t=t;
};
void Record::setGemoglobin(int gemoglobin){
    this->gemoglobin=gemoglobin;
};
/*Record::Record(const Record &r) noexcept
{
            this->num = r.num;
            this->surname =r.surname;
            this->name = r.name;
            this->year = r.year;
            this->sex = r.sex;
            this->t = r.t;
            this->gemoglobin = r.gemoglobin;
}*/
Record::Record()
{
            num = 0;
            surname = "-";
            name = "-";
            year = 0;
            sex = "-";
            t = 0;
            gemoglobin = 0;
}


Record::Record(int num, QString surname,QString name,  int year,QString sex, double t,int gemoglobin){
    this->num=num;
    this->surname = surname;
    this->name=name;
    this->year=year;
    this->sex=sex;
    this->t=t;
    this->gemoglobin=gemoglobin;
};
 QTextStream & operator <<(QTextStream &in, const Record &r)
{
    in<<QString::number(r.num)+" "<< QString(r.surname)+" " << QString(r.name)+" "<< QString::number(r.year)+" "<< QString(r.sex)+" "<<QString::number(r.t)+" "<< QString::number(r.gemoglobin) + "\n";
    return in;
}

QTextStream & operator >>(QTextStream &out, Record &r)
{
    out >>r.num>> r.surname >> r.name >> r.year >> r.sex >> r.t >> r.gemoglobin ;
    r = Record(r.num,r.surname,r.name,r.year,r.sex,r.t,r.gemoglobin);

    return out;
}

bool operator== (const Record &r1, const Record &r2){
    return (r1.num==r2.num &&
            r1.surname == r2.surname &&
            r1.name==r2.name &&
            r1.year==r2.year &&
            r1.sex==r2.sex &&
            r1.t==r2.t &&
            r1.gemoglobin==r2.gemoglobin);
}
bool operator!= (const Record &r1, const Record &r2){
    return !(r1.num==r2.num &&
            r1.surname == r2.surname &&
            r1.name==r2.name &&
            r1.year==r2.year &&
            r1.sex==r2.sex &&
            r1.t==r2.t &&
            r1.gemoglobin==r2.gemoglobin);
}
