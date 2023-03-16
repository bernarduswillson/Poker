#ifndef __CARD_HPP__
#define __CARD_HPP__

#include <iostream>
#include <string>
#include <cmath>
#include "../Calculable/Calculable.hpp"

class Card : virtual public Calculable
{
private:
    double number;
    double color;

    public:
        //constructor
        Card(double, double);
        void operator=(const Card &other);
        bool operator>(const Card &other);
        bool operator<(const Card &other);
        
        //destructor
        ~Card();
        virtual double getValue();
        double getNumber();
        double getColor();
        void setValue(double value);
        void displayCard();
        
};

#endif