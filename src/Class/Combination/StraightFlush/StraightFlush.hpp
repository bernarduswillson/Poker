#include "../../Package/Package.hpp"
#include "../../Card/Card.hpp"

#include <iostream>
class StraightFlush :public Package
{
private:
    std::string name;
public:
    //constructor
    StraightFlush();
    //destructor
    ~StraightFlush();
    double getValue();
    std::string getName();
    void setValue(double value);
};