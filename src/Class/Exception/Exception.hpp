#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

#include <string>

class Exception
{
public:
    Exception();
    ~Exception();
    virtual std::string what() const = 0;
};

class MenuException : public Exception
{
public:
    MenuException();
    ~MenuException();
    std::string what() const;
};

class ActionException : public Exception
{
public:
    ActionException();
    ~ActionException();
    std::string what() const;
};

class TargetException : public Exception
{
public:
    TargetException();
    ~TargetException();
    std::string what() const;
};

#endif