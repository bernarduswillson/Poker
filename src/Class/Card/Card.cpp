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
    double x = this->value;
    if (floor(x * 10) == 1)
    {
        if (round(fmod(x * 100, 10)) == 3)
        {
            std::cout << "\033[34m"
                      << "1"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 6)
        {
            std::cout << "\033[33m"
                      << "1"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 9)
        {
            std::cout << "\033[31m"
                      << "1"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 0)
        {
            std::cout << "\033[32m"
                      << "1"
                      << "\033[0m";
        }
    }
    else if (floor(x * 10) == 2)
    {
        if (round(fmod(x * 100, 10)) == 3)
        {
            std::cout << "\033[34m"
                      << "2"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 6)
        {
            std::cout << "\033[33m"
                      << "2"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 9)
        {
            std::cout << "\033[31m"
                      << "2"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 0)
        {
            std::cout << "\033[32m"
                      << "2"
                      << "\033[0m";
        }
    }
    else if (floor(x * 10) == 3)
    {
        if (round(fmod(x * 100, 10)) == 3)
        {
            std::cout << "\033[34m"
                      << "3"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 6)
        {
            std::cout << "\033[33m"
                      << "3"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 9)
        {
            std::cout << "\033[31m"
                      << "3"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 0)
        {
            std::cout << "\033[32m"
                      << "3"
                      << "\033[0m";
        }
    }
    else if (floor(x * 10) == 4)
    {
        if (round(fmod(x * 100, 10)) == 3)
        {
            std::cout << "\033[34m"
                      << "4"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 6)
        {
            std::cout << "\033[33m"
                      << "4"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 9)
        {
            std::cout << "\033[31m"
                      << "4"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 0)
        {
            std::cout << "\033[32m"
                      << "4"
                      << "\033[0m";
        }
    }
    else if (floor(x * 10) == 5)
    {
        if (round(fmod(x * 100, 10)) == 3)
        {
            std::cout << "\033[34m"
                      << "5"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 6)
        {
            std::cout << "\033[33m"
                      << "5"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 9)
        {
            std::cout << "\033[31m"
                      << "5"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 0)
        {
            std::cout << "\033[32m"
                      << "5"
                      << "\033[0m";
        }
    }
    else if (floor(x * 10) == 6)
    {
        if (round(fmod(x * 100, 10)) == 3)
        {
            std::cout << "\033[34m"
                      << "6"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 6)
        {
            std::cout << "\033[33m"
                      << "6"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 9)
        {
            std::cout << "\033[31m"
                      << "6"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 0)
        {
            std::cout << "\033[32m"
                      << "6"
                      << "\033[0m";
        }
    }
    else if (floor(x * 10) == 7)
    {
        if (round(fmod(x * 100, 10)) == 3)
        {
            std::cout << "\033[34m"
                      << "7"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 6)
        {
            std::cout << "\033[33m"
                      << "7"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 9)
        {
            std::cout << "\033[31m"
                      << "7"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 0)
        {
            std::cout << "\033[32m"
                      << "7"
                      << "\033[0m";
        }
    }
    else if (floor(x * 10) == 8)
    {
        if (round(fmod(x * 100, 10)) == 3)
        {
            std::cout << "\033[34m"
                      << "8"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 6)
        {
            std::cout << "\033[33m"
                      << "8"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 9)
        {
            std::cout << "\033[31m"
                      << "8"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 0)
        {
            std::cout << "\033[32m"
                      << "8"
                      << "\033[0m";
        }
    }
    else if (floor(x * 10) == 9)
    {
        if (round(fmod(x * 100, 10)) == 3)
        {
            std::cout << "\033[34m"
                      << "9"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 6)
        {
            std::cout << "\033[33m"
                      << "9"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 9)
        {
            std::cout << "\033[31m"
                      << "9"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 0)
        {
            std::cout << "\033[32m"
                      << "9"
                      << "\033[0m";
        }
    }
    else if (floor(x * 10) == 10)
    {
        if (round(fmod(x * 100, 10)) == 3)
        {
            std::cout << "\033[34m"
                      << "10"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 6)
        {
            std::cout << "\033[33m"
                      << "10"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 9)
        {
            std::cout << "\033[31m"
                      << "10"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 0)
        {
            std::cout << "\033[32m"
                      << "10"
                      << "\033[0m";
        }
    }
    else if (floor(x * 10) == 11)
    {
        if (round(fmod(x * 100, 10)) == 3)
        {
            std::cout << "\033[34m"
                      << "11"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 6)
        {
            std::cout << "\033[33m"
                      << "11"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 9)
        {
            std::cout << "\033[31m"
                      << "11"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 0)
        {
            std::cout << "\033[32m"
                      << "11"
                      << "\033[0m";
        }
    }
    else if (floor(x * 10) == 12)
    {
        if (round(fmod(x * 100, 10)) == 3)
        {
            std::cout << "\033[34m"
                      << "12"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 6)
        {
            std::cout << "\033[33m"
                      << "12"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 9)
        {
            std::cout << "\033[31m"
                      << "12"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 0)
        {
            std::cout << "\033[32m"
                      << "12"
                      << "\033[0m";
        }
    }
    else if (floor(x * 10) == 13)
    {
        if (round(fmod(x * 100, 10)) == 3)
        {
            std::cout << "\033[34m"
                      << "13"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 6)
        {
            std::cout << "\033[33m"
                      << "13"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 9)
        {
            std::cout << "\033[31m"
                      << "13"
                      << "\033[0m";
        }
        else if (round(fmod(x * 100, 10)) == 0)
        {
            std::cout << "\033[32m"
                      << "13"
                      << "\033[0m";
        }
    }
}