#include "../../Package/Package.hpp"
#include "../../Card/Card.hpp"

#include <iostream>
class ThreeOfAKind :public Package
{
private:
    std::string name;
public:
    //constructor
    ThreeOfAKind(std::vector<Card>);
    //destructor
    ~ThreeOfAKind();
    double getValue();
    std::string getName();
    void setValue(double value);
};