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

const char* MenuException::what() const
{
    return "Menu unavailable\n";
}

ActionException::ActionException()
{
}

ActionException::~ActionException()
{
}

const char* ActionException::what() const
{
    return "Action unavailable\n";
}

TargetException::TargetException()
{
}

TargetException::~TargetException()
{
}

const char* TargetException::what() const
{
    return "Target unavailable\n";
}