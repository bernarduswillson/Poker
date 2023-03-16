#include "../../Package/Package.hpp"
#include "../../Card/Card.hpp"

#include <iostream>
class HighCard :public Package
{
private:
    std::string name;
public:
    //constructor
    HighCard(std::vector<Card>);
    //destructor
    ~HighCard();
    double getValue();
    std::string getName();
    void setValue(double value);
};