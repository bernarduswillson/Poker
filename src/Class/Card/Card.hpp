#include <iostream>
#include <string>
#include "../Calculable/Calculable.hpp"

class Card : virtual public Calculable
{
    private:
        double number;
        double color;

    public:
        //constructor
        Card(double, double);
        //destructor
        ~Card();
        virtual double getValue();
        double getNumber();
        double getColor();
        void setValue(double value);
        
};