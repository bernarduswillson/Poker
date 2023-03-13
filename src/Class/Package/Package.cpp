#include "Package.hpp"

Package::Package():Calculable(0)
{
    this->cardBuffer = std::vector<Card>();
    this->vallll = 0;

}

Package::~Package()
{
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