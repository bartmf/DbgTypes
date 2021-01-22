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

DbgFloat DbgFloat::operator +(DbgFloat &f_num2) // доработать проверку на переполнение
{
    double temp = f_num + f_num2.getNum();
    if(temp > statf_globalCount || temp < (statf_globalCount + 1.0) * (-1.0)){
        throw OverflowException("Переполнение при сложении", __LINE__, __FILE__);
    }

    /*if  ((f_num>0 && f_num2>0 && f_num > statf_globalCount - f_num2)

         || (f_num < 0 && f_num2 < 0 && f_num < (((statf_globalCount + 1) * (-1)) - f_num2))){
        s_Exception.append(1, __LINE__);
        s_Exception.append("\nФайл: ");
        s_Exception.append(__FILE__);
        s_Exception.append("\n\n");
        //printf("Line: %d\n File: %s\n", __LINE__, __FILE__);

        throw OverflowException (s_Exception);
    }
    */
    return f_num + f_num2;
}

DbgFloat DbgFloat::operator - (DbgFloat &f_num2) // доработать проверку на переполнение
{
    double temp = f_num - f_num2.getNum();
    if(temp > statf_globalCount || temp < (statf_globalCount + 1.0) * (-1.0)){
        throw OverflowException("Переполнение при разности", __LINE__, __FILE__);
    }
    return f_num - f_num2.getNum();
}

DbgFloat DbgFloat::operator *(DbgFloat &f_num2) // доработать проверку на переполнение
{
    double temp = f_num * f_num2;
    if(temp > statf_globalCount || temp < (statf_globalCount + 1.0) * (-1.0)){
        throw OverflowException("Переполнение при умножении", __LINE__, __FILE__);
    }
    return f_num * f_num2;
}

DbgFloat DbgFloat::operator /(DbgFloat &f_num2) // доработать проверку на переполнение
{
    double temp = f_num / f_num2;
    if((temp > statf_globalCount) || ( temp < ((statf_globalCount + 1.0) * (-1.0)))){
        throw OverflowException("Переполнение при делении", __LINE__, __FILE__);
    }
    return f_num / f_num2;
}

DbgFloat DbgFloat::operator =(DbgFloat f_num2) //доработать проверку на переполнение
{
    if(f_num2 > statf_globalCount || f_num2 < ((statf_globalCount + 1.0) * (-1.0))){
        throw OverflowException("Переполнение при присвоении", __LINE__, __FILE__);
    }
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
