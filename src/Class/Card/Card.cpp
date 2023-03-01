#include "Card.hpp"


Card::Card() {
    value = 0;
}

Card::Card(double number, std::string color) {
    double vals = number * 0.1;
    if (color == "green") {
        this->value = vals;
    } 
    else if (color == "blue") {
        this->value = vals + 0.03;
    } 
    else if (color == "yellow") {
        this->value = vals + 0.06;
    }
    else if (color == "red") {
        this->value = vals + 0.09;
    }
    else {
        std::cout << "kartu anda salah goblok" << std::endl;
        this->value = 0;
    }
}

double Card::getValue() {
    return this->value;
}

int main(int argc, char const *argv[])
{
    double x;
    std::string y;
    std::cin >> x >> y;
    Card card(x, y);
    std::cout << card.getValue() << std::endl;
    return 0;
}