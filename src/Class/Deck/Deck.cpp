#include "Deck.hpp"

// === CONSTRUCTOR DESTRUCTOR ==================================

template <typename T>
Deck<T>::Deck() : InventoryHolder() {}

template <typename T>
Deck<T>::~Deck()
{
    for (int i = 0; i < this->buffer.size(); i++)
    {
        delete this->getElmt(i);
    }
}

// === GETTER ==================================================

template <typename T>
int Deck<T>::getLength()
{
    return this->length;
}

template <typename T>
T Deck<T>::getElmt(int index)
{
    return this->buffer[index];
}

// === METHODS =================================================

template <typename T>
void Deck<T>::push(const T &other)
{
    this->buffer.push_back(other);
}

template <typename T>
void Deck<T>::shuffle()
{
    int swapidx1 = 0;
    int swapidx2 = 0;
    for (int i = 0; i < (300 + (std::rand() % (201))); i++)
    {
        swapidx1 = (std::rand() % 52);
        while (swapidx2 == swapidx1)
        {
            swapidx2 = (std::rand() & 52);
        }

        T temp = T(this->buffer[swapidx1]);
        this->buffer[swapidx1] = this->buffer[swapidx2];
        this->buffer[swapidx2] = temp;
    }
}
