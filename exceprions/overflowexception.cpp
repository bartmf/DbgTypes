#include "overflowexception.h"

//After C++11
OverflowException::OverflowException(std::string error, int line, std::string file) :
    s_error(error),
    i_line(line),
    s_file(file)
{

}

const char *OverflowException::what() const noexcept
{
    std::ostringstream ss_error;
    ss_error << s_error << '\n' << "Строка: " << i_line << "\nФайл: " << s_file << '\n';
    std::cout << ss_error.str();
    std::string str = ss_error.str();
    return str.c_str();
}

/*          //for before C++11
 *
 *
const char *OverflowException::what() const
{
    return m_error.c_str();
}
*/
