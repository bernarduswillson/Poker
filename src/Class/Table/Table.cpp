#include <iostream>
#include "Table.hpp"

// === CONSTRUCTOR DESTRUCTOR ==================================
Table::Table()
{
    this->length = 0;
}
Table::~Table() {}

// === GETTER ==================================================
int Table::getLength()
{
    return this->length;
}

Card Table::getElmt(int index)
{
    return this->buffer[index];
}
std::vector<Card> Table::getBuffer()
{
    return this->buffer;
}

// === DISPLAY =================================================
void Table::display(int round)
{
    for (int i = 0; i < round - 1; i++)
    {
        this->getElmt(i).displayCard();
        std::cout << " ";
    }
    for (int i = 0; i < 6 - round; i++)
    {
        std::cout << "# ";
    }
    std::cout << std::endl;
}

// === METHODS =================================================
void Table::push(Card card)
{
    this->buffer.push_back(card);
    this->length++;
}

Card Table::pop()
{
    Card temp = this->buffer[0];
    std::vector<Card>::iterator itr = this->buffer.begin();
    this->buffer.erase(itr);
    this->length--;
    return temp;
}