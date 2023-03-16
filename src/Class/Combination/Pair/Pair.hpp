#ifndef __PAIR_HPP__
#define __PAIR_HPP__

#include "../../Package/Package.hpp"
#include "../../Card/Card.hpp"

#include <iostream>
class Pair :public Package
{
private:
    std::string name;
public:
    //constructor
    Pair(std::vector<Card>);
    //destructor
    ~Pair();
    double getValue();
    std::string getName();
    void setValue(double value);
};

#endif