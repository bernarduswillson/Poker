#ifndef __PACKAGE_HPP__
#define __PACKAGE_HPP__

#include "../Calculable/Calculable.hpp"
#include "../Card/Card.hpp"
#include <vector>

class Package : virtual public Calculable
{
private:
    std::vector<Card> cardBuffer;
    std::string name;

public:
    // constructor
    Package();
    // copy constructor
    void operator=(const Package &other);
    // destructor
    ~Package();
    virtual void setValue(double value);
    virtual double getValue();
    virtual std::string getName();
    std::vector<Card> getCardBuffer();

    bool operator>=(Package &);

    void addCard(Card);
};

#endif