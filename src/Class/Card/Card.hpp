#include <iostream>
#include <string>
#include "../Calculable/Calculable.hpp"

class Card : virtual public Calculable
{
    private:
        int number;
        std::string color;

    public:
        //constructor
        Card();
        //destructor
        ~Card();
        virtual double getValue();
        int getNumber();
        std::string getColor();
        void setValue(double value);
        
};