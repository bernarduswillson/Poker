#include "../../Package/Package.hpp"
#include "../../Card/Card.hpp"

#include <iostream>
class FourOfAKind :public Package
{
private:
    std::string name;
public:
    //constructor
    FourOfAKind();
    //destructor
    ~FourOfAKind();
    double getValue();
    std::string getName();
    void setValue(double value);
};