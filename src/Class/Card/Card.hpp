#ifndef __CARD_HPP__
#define __CARD_HPP__

#include <iostream>
#include <string>

class Card
{
private:
    double value;
    std::string color;
    int number;

public:
    // Constructor and Destructor
    Card();
    Card(int number, std::string color);
    ~Card();

    // Getter and Setter
    double getValue();

    // Methods
    void displaycard();

};

#endif