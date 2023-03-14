#include "../../Package/Package.hpp"
#include "../../Card/Card.hpp"

#include <iostream>
class Flush :public Package
{
private:
    std::string name;
public:
    //constructor
    Flush();
    //destructor
    ~Flush();
    double getValue();
    std::string getName();
    void setValue(double value);
};