#include "InventoryHolder.hpp"

// === CONSTRUCTOR DESTRUCTOR ==================================

template <typename T>
InventoryHolder<T>::InventoryHolder(int size)
{
    this->size = size;
    this->length = 0;
    this->buffer = new T[size];
}

template <typename T>
void InventoryHolder<T>::operator=(const InventoryHolder &other)
{
    this->size = other.size;
    this->length = other.length;
    this->buffer = new T[this->size];
    for (int i = 0; i < this->length; i++)
    {
        this->buffer[i] = other.buffer[i];
    }
}

template <typename T>
InventoryHolder<T>::~InventoryHolder()
{
    delete this->buffer;
}

// === GETTER ==================================================

template <typename T>
int InventoryHolder<T>::getLength()
{
    return this->length;
}

template <typename T>
T InventoryHolder<T>::getElmt(int index)
{
    return this->buffer[index];
}

// === OPERATOR OVERLOADING ====================================

template <typename T>
InventoryHolder<T> InventoryHolder<T>::operator+(const T &addedElmt)
{
    InventoryHolder ret(this->size);
    ret = *this;

    ret.buffer[ret.length] = addedElmt;
    ret.length++;
    return ret;
}