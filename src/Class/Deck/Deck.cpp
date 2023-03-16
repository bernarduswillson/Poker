#include "Deck.hpp"
#include <ctime>
#include <algorithm>

// === CONSTRUCTOR DESTRUCTOR ==================================

template <typename T>
Deck<T>::Deck() : InventoryHolder() {}

template <typename T>
void Deck<T>::operator=(Deck<T> &other)
{
    this->buffer = other.buffer;
}

template <typename T>
Deck<T>::~Deck() {}

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
    this->length++;
}

template <typename T>
void Deck<T>::pop()
{
    this->buffer.pop_back();
    this->length--;
}

template <typename T>
void Deck<T>::shuffle()
{
    // std::srand(time(0));
    // int swapidx1 = 0;
    // int swapidx2 = 0;
    // for (int i = 0; i < (300 + (std::rand() % (201))); i++)
    // {
    //     swapidx1 = (std::rand() % 52);
    //     swapidx2 = (std::rand() % 52);
    //     while (swapidx2 == swapidx1)
    //     {
    //         swapidx2 = (std::rand() & 52);
    //     }

    //     T temp = T(this->buffer[swapidx1]);
    //     this->buffer[swapidx1] = this->buffer[swapidx2];
    //     this->buffer[swapidx2] = temp;
    // }
    std::random_shuffle(this->buffer.begin(), this->buffer.end());
    // std::shuffle(this->buffer.begin(), this->buffer.end(), g);
}

template <typename T>
T Deck<T>::roll()
{
    T temp = T(this->buffer[this->length - 1]);
    this->pop();
    return temp;
}

template <typename T>
void Deck<T>::resetBuffer()
{
    int size = this->buffer.size();
    for (int i = 0; i < size; i++)
    {
        this->buffer.pop_back();
    }
    this->length = 0;
}
