#include <iostream>

//create abstract class
class Calculable
{
    protected:
        double value;

    public:
        //constructor
        Calculable();
        //destructor
        virtual ~Calculable();
        virtual double getValue() = 0;
        bool operator>(Calculable &obj);
        bool operator<(Calculable &obj);
        bool operator=(Calculable &obj);
        virtual void setValue(double value) = 0;
};
