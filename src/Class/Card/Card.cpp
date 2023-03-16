#include "Card.hpp"

Card::Card(double number, double color) : Calculable()
{
    this->number = number;
    this->color = color;
    this->value = number * 0.1 + color * 0.03;
}

void Card::operator=(const Card &other)
{
    this->number = other.number;
    this->color = other.color;
    this->value = other.value;
}

bool Card::operator>(const Card &other)
{
    return this->value > other.value;
}

bool Card::operator<(const Card &other)
{
    return this->value < other.value;
}

Card::~Card()
{
}

double Card::getValue()
{
    return this->value;
}

double Card::getNumber()
{
    return number;
}

double Card::getColor()
{
    return color;
}

void Card::setValue(double value)
{
    this->value = value;
}

// === DISPLAY =================================================
void Card::displayCard()
{
    if (this->number == 1)
    {
        if (this->color == 1)
        {
            std::cout << "\033[34m"
                      << "1"
                      << "\033[0m";
        }
        else if (this->color == 2)
        {
            std::cout << "\033[33m"
                      << "1"
                      << "\033[0m";
        }
        else if (this->color == 3)
        {
            std::cout << "\033[31m"
                      << "1"
                      << "\033[0m";
        }
        else if (this->color == 0)
        {
            std::cout << "\033[32m"
                      << "1"
                      << "\033[0m";
        }
    }
    else if (this->number == 2)
    {
        if (this->color == 1)
        {
            std::cout << "\033[34m"
                      << "2"
                      << "\033[0m";
        }
        else if (this->color == 2)
        {
            std::cout << "\033[33m"
                      << "2"
                      << "\033[0m";
        }
        else if (this->color == 3)
        {
            std::cout << "\033[31m"
                      << "2"
                      << "\033[0m";
        }
        else if (this->color == 0)
        {
            std::cout << "\033[32m"
                      << "2"
                      << "\033[0m";
        }
    }
    else if (this->number == 3)
    {
        if (this->color == 1)
        {
            std::cout << "\033[34m"
                      << "3"
                      << "\033[0m";
        }
        else if (this->color == 2)
        {
            std::cout << "\033[33m"
                      << "3"
                      << "\033[0m";
        }
        else if (this->color == 3)
        {
            std::cout << "\033[31m"
                      << "3"
                      << "\033[0m";
        }
        else if (this->color == 0)
        {
            std::cout << "\033[32m"
                      << "3"
                      << "\033[0m";
        }
    }
    else if (this->number == 4)
    {
        if (this->color == 1)
        {
            std::cout << "\033[34m"
                      << "4"
                      << "\033[0m";
        }
        else if (this->color == 2)
        {
            std::cout << "\033[33m"
                      << "4"
                      << "\033[0m";
        }
        else if (this->color == 3)
        {
            std::cout << "\033[31m"
                      << "4"
                      << "\033[0m";
        }
        else if (this->color == 0)
        {
            std::cout << "\033[32m"
                      << "4"
                      << "\033[0m";
        }
    }
    else if (this->number == 5)
    {
        if (this->color == 1)
        {
            std::cout << "\033[34m"
                      << "5"
                      << "\033[0m";
        }
        else if (this->color == 2)
        {
            std::cout << "\033[33m"
                      << "5"
                      << "\033[0m";
        }
        else if (this->color == 3)
        {
            std::cout << "\033[31m"
                      << "5"
                      << "\033[0m";
        }
        else if (this->color == 0)
        {
            std::cout << "\033[32m"
                      << "5"
                      << "\033[0m";
        }
    }
    else if (this->number == 6)
    {
        if (this->color == 1)
        {
            std::cout << "\033[34m"
                      << "6"
                      << "\033[0m";
        }
        else if (this->color == 2)
        {
            std::cout << "\033[33m"
                      << "6"
                      << "\033[0m";
        }
        else if (this->color == 3)
        {
            std::cout << "\033[31m"
                      << "6"
                      << "\033[0m";
        }
        else if (this->color == 0)
        {
            std::cout << "\033[32m"
                      << "6"
                      << "\033[0m";
        }
    }
    else if (this->number == 7)
    {
        if (this->color == 1)
        {
            std::cout << "\033[34m"
                      << "7"
                      << "\033[0m";
        }
        else if (this->color == 2)
        {
            std::cout << "\033[33m"
                      << "7"
                      << "\033[0m";
        }
        else if (this->color == 3)
        {
            std::cout << "\033[31m"
                      << "7"
                      << "\033[0m";
        }
        else if (this->color == 0)
        {
            std::cout << "\033[32m"
                      << "7"
                      << "\033[0m";
        }
    }
    else if (this->number == 8)
    {
        if (this->color == 1)
        {
            std::cout << "\033[34m"
                      << "8"
                      << "\033[0m";
        }
        else if (this->color == 2)
        {
            std::cout << "\033[33m"
                      << "8"
                      << "\033[0m";
        }
        else if (this->color == 3)
        {
            std::cout << "\033[31m"
                      << "8"
                      << "\033[0m";
        }
        else if (this->color == 0)
        {
            std::cout << "\033[32m"
                      << "8"
                      << "\033[0m";
        }
    }
    else if (this->number == 9)
    {
        if (this->color == 1)
        {
            std::cout << "\033[34m"
                      << "9"
                      << "\033[0m";
        }
        else if (this->color == 2)
        {
            std::cout << "\033[33m"
                      << "9"
                      << "\033[0m";
        }
        else if (this->color == 3)
        {
            std::cout << "\033[31m"
                      << "9"
                      << "\033[0m";
        }
        else if (this->color == 0)
        {
            std::cout << "\033[32m"
                      << "9"
                      << "\033[0m";
        }
    }
    else if (this->number == 10)
    {
        if (this->color == 1)
        {
            std::cout << "\033[34m"
                      << "10"
                      << "\033[0m";
        }
        else if (this->color == 2)
        {
            std::cout << "\033[33m"
                      << "10"
                      << "\033[0m";
        }
        else if (this->color == 3)
        {
            std::cout << "\033[31m"
                      << "10"
                      << "\033[0m";
        }
        else if (this->color == 0)
        {
            std::cout << "\033[32m"
                      << "10"
                      << "\033[0m";
        }
    }
    else if (this->number == 11)
    {
        if (this->color == 1)
        {
            std::cout << "\033[34m"
                      << "11"
                      << "\033[0m";
        }
        else if (this->color == 2)
        {
            std::cout << "\033[33m"
                      << "11"
                      << "\033[0m";
        }
        else if (this->color == 3)
        {
            std::cout << "\033[31m"
                      << "11"
                      << "\033[0m";
        }
        else if (this->color == 0)
        {
            std::cout << "\033[32m"
                      << "11"
                      << "\033[0m";
        }
    }
    else if (this->number == 12)
    {
        if (this->color == 1)
        {
            std::cout << "\033[34m"
                      << "12"
                      << "\033[0m";
        }
        else if (this->color == 2)
        {
            std::cout << "\033[33m"
                      << "12"
                      << "\033[0m";
        }
        else if (this->color == 3)
        {
            std::cout << "\033[31m"
                      << "12"
                      << "\033[0m";
        }
        else if (this->color == 0)
        {
            std::cout << "\033[32m"
                      << "12"
                      << "\033[0m";
        }
    }
    else if (this->number == 13)
    {
        if (this->color == 1)
        {
            std::cout << "\033[34m"
                      << "13"
                      << "\033[0m";
        }
        else if (this->color == 2)
        {
            std::cout << "\033[33m"
                      << "13"
                      << "\033[0m";
        }
        else if (this->color == 3)
        {
            std::cout << "\033[31m"
                      << "13"
                      << "\033[0m";
        }
        else if (this->color == 0)
        {
            std::cout << "\033[32m"
                      << "13"
                      << "\033[0m";
        }
    }
}
