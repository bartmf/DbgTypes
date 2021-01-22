#ifndef OVERFLOWFLOATEXCEPTION_H
#define OVERFLOWFLOATEXCEPTION_H
#include <iostream>

class OverflowException: public std::exception
{
private:
    std::string m_error;
public:
    OverflowException(std::string error);
    const char* what() const noexcept;

    //For before C++11
    //const char* what() const;
};

#endif // OVERFLOWFLOATEXCEPTION_H
