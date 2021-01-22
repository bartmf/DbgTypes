#ifndef OVERFLOWFLOATEXCEPTION_H
#define OVERFLOWFLOATEXCEPTION_H
#include <iostream>
#include <sstream>

class OverflowException: public std::exception
{
private:
    std::string s_error;
    int i_line;
    std::string s_file;
public:
    OverflowException(std::string error, int line, std::string file);
    const char* what() const noexcept;
    //For before C++11
    //const char* what() const;
};

#endif // OVERFLOWFLOATEXCEPTION_H
