#include "../../Package/Package.hpp"
#include "../../Card/Card.hpp"

#include <iostream>
class TwoPair :public Package
{
private:
    std::string name;
public:
    //constructor
    TwoPair();
    //destructor
    ~TwoPair();
    double getValue();
    std::string getName();
    void setValue(double value);
};