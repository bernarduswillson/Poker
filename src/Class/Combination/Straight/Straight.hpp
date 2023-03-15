#include "../../Package/Package.hpp"
#include "../../Card/Card.hpp"

#include <iostream>
class Straight :public Package
{
private:
    std::string name;
public:
    //constructor
    Straight(std::vector<Card>);
    //destructor
    ~Straight();
    double getValue();
    std::string getName();
    void setValue(double value);
};