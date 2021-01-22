#include "overflowexception.h"

//After C++11
OverflowException::OverflowException(std::string error) : m_error(error)
{

}

const char *OverflowException::what() const noexcept
{
    return m_error.c_str();
}

/*          //for before C++11
 *
 *
const char *OverflowException::what() const
{
    return m_error.c_str();
}
*/
