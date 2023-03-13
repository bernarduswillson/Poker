#include "../../Package/Package.hpp"
#include "../../Card/Card.hpp"

#include <iostream>
class ThreeOfAKind :public Package
{
private:
    std::string name;
public:
    //constructor
    ThreeOfAKind();
    //destructor
    ~ThreeOfAKind();
    double getValue();
    std::string getName();
    void setValue(double value);
};