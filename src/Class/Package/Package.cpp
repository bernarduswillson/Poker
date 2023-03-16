#include "Package.hpp"

Package::Package() : Calculable()
{
    this->cardBuffer = std::vector<Card>();
}

void Package::operator=(const Package &other)
{
    this->cardBuffer = other.cardBuffer;
    this->value = other.value;
}

Package::~Package()
{
}

double Package::getValue()
{
    return value;
}

std::vector<Card> Package::getCardBuffer()
{
    return cardBuffer;
}

void Package::addCard(Card card)
{
    cardBuffer.push_back(card);
}

void Package::setValue(double value)
{
    this->value = value;
}

std::string Package::getName()
{
    return name;
}

bool Package::operator>=(Package &other)
{
    return this->getValue() >= other.getValue();
}
