#include "../../Package/Package.hpp"
#include "../../Card/Card.hpp"

#include <iostream>
class Pair :public Package
{
private:
    std::string name;
public:
    //constructor
    Pair();
    //destructor
    ~Pair();
    double getValue();
    std::string getName();
    void setValue(double value);
};