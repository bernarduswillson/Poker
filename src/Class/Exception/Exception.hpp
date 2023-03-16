#ifndef __Exception_HPP__
#define __Exception_HPP__

class Exception
{
public:
    Exception();
    ~Exception();
    virtual const char* what() const = 0;
};

class MenuException : public Exception
{
public:
    MenuException();
    ~MenuException();
    const char* what() const;
};

class ActionException : public Exception
{
public:
    ActionException();
    ~ActionException();
    const char* what() const;
};

class TargetException : public Exception
{
public:
    TargetException();
    ~TargetException();
    const char* what() const;
};



#endif