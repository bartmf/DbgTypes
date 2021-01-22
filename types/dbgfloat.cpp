#include "dbgfloat.h"

float DbgFloat::statf_globalCount = __FLT_MAX__;

DbgFloat::DbgFloat(){ //инициализация типа данных

}

DbgFloat::DbgFloat(float f_num2){ //инициализация типа данных
    f_num = f_num2;
}

DbgFloat::operator float() const
{
    return this->f_num;
}


void DbgFloat::setGlobalCount(float newGlobalCount)
{
     DbgFloat::statf_globalCount = newGlobalCount;
}

void DbgFloat::setLocaleCount(const float f_localCount)
{
    this->f_localCount = f_localCount;
}

void DbgFloat::setNum(float f_num)
{
    this->f_num = f_num;
}

float DbgFloat::getGlobalCount()
{
    return  DbgFloat::statf_globalCount;
}

float DbgFloat::getLocalCount()
{
    return f_localCount;
}

float DbgFloat::getNum()
{
    return f_num;
}

DbgFloat DbgFloat::operator +(DbgFloat f_num2) // доработать проверку на переполнение
{

    if  ((f_num>0 && f_num2>0 && f_num > statf_globalCount - f_num2)

         || (f_num < 0 && f_num2 < 0 && f_num < (((statf_globalCount + 1) * (-1)) - f_num2))){
        s_Exception.append(1, __LINE__);
        s_Exception.append("\nФайл: ");
        s_Exception.append(__FILE__);
        s_Exception.append("\n\n");
        //printf("Line: %d\n File: %s\n", __LINE__, __FILE__);

        throw OverflowException (s_Exception);
    }
    return f_num + f_num2;
}

DbgFloat DbgFloat::operator - (DbgFloat &f_num2) // доработать проверку на переполнение
{
    if((f_num < 0 && f_num2.getNum() > 0 && f_num < f_num < (((statf_globalCount + 1) * (-1)) - f_num2.getNum()))
            || (f_num > 0 && f_num2.getNum() < 0 && f_num2.getNum() < (((statf_globalCount + 1) * (-1)) - f_num))){
        throw OverflowException("Переполнение при вычитании");
    }
    return f_num - f_num2.getNum();
}

DbgFloat DbgFloat::operator *(DbgFloat &f_num2) // доработать проверку на переполнение
{
    double temp = f_num * f_num2;
    if(temp > statf_globalCount){
        throw OverflowException("Переполнение при умножении");
    }
    return f_num * f_num2;
}

DbgFloat DbgFloat::operator /(DbgFloat &f_num2) // доработать проверку на переполнение
{
    double temp = f_num / f_num2;
    if((temp > 0 && temp > statf_globalCount) || (temp < 0 && temp < statf_globalCount)){
        throw OverflowException("Переполнение при делении");
    }
    return f_num / f_num2;
}

DbgFloat DbgFloat::operator = (DbgFloat f_num2) //доработать проверку на переполнение
{
    setNum(f_num2);
    return f_num;
}

bool DbgFloat::operator ==(DbgFloat &f_num2)
{
    return f_num == f_num2 ? true : false;
}

bool DbgFloat::operator >(DbgFloat &f_num2)
{
    return f_num > f_num2 ? true : false;
}

bool DbgFloat::operator >=(DbgFloat &f_num2)
{
    return f_num >= f_num2 ? true : false;
}

bool DbgFloat::operator <(DbgFloat &f_num2)
{
    return f_num < f_num2 ? true : false;
}

bool DbgFloat::operator <=(DbgFloat &f_num2)
{
    return f_num <= f_num2 ? true : false;
}

std::string DbgFloat::lastExceptions(){
    return s_Exception;
}

DbgFloat::~DbgFloat()
{

}
