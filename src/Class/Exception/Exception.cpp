#include "Exception.hpp"

Exception::Exception()
{
}

Exception::~Exception()
{
}

MenuException::MenuException()
{
}

MenuException::~MenuException()
{
}

std::string MenuException::what() const
{
    return "Menu unavailable\n";
}

ActionException::ActionException()
{
}

ActionException::~ActionException()
{
}

std::string ActionException::what() const
{
    return "Action unavailable\n";
}

TargetException::TargetException()
{
}

TargetException::~TargetException()
{
}

std::string TargetException::what() const
{
    return "Target unavailable\n";
}