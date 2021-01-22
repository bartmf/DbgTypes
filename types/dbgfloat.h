#include <iostream>
#include "../exceprions/overflowexception.h"
#ifndef DBGFLOAT_H
#define DBGFLOAT_H


class DbgFloat
{
private:
    float f_num;
    static float statf_globalCount;
    float f_localCount = __FLT_MAX__;
    std::string s_Exception = "Переполнение типа float по глобальному пределу.\nСтрочка: ";

public:
    DbgFloat ();
    DbgFloat (const float);
    static void setGlobalCount(float);
    void setLocaleCount(float);
    void setNum(float);
    static float getGlobalCount();
    float getLocalCount();
    float getNum();
    operator float() const;
    DbgFloat operator + (const DbgFloat num2);
    DbgFloat operator - (DbgFloat &num2);
    DbgFloat operator * (DbgFloat &num2);
    DbgFloat operator / (DbgFloat &num2);
    DbgFloat operator = (DbgFloat num2);
    bool operator == (DbgFloat &num2);
    bool operator > (DbgFloat &num2);
    bool operator >= (DbgFloat &num2);
    bool operator < (DbgFloat &num2);
    bool operator <= (DbgFloat &num2);

    std::string lastExceptions ();

    ~DbgFloat ();
};

#endif // DBGFLOAT_H
