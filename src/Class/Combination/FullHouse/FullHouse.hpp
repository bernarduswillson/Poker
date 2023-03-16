#include "../../Package/Package.hpp"
#include "../../Card/Card.hpp"

#include <iostream>
class FullHouse :public Package
{
private:
    std::string name;
public:
    //constructor
    FullHouse(std::vector<Card>);
    //destructor
    ~FullHouse();
    double getValue();
    std::string getName();
    void setValue(double value);
};