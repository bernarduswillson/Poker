#ifndef __INVENTORY_HOLDER_HPP__
#define __INVENTORY_HOLDER_HPP__

#include <iterator>

template <class T>
class InventoryHolder
{
private:
    int size;
    int length;
    T *buffer;

public:
    // === CONSTRUCTOR DESTRUCTOR ==================================
    InventoryHolder(int);
    void operator=(const InventoryHolder &);
    ~InventoryHolder();

    // === GETTER ==================================================
    int getLength();
    T getElmt(int);

    // === OPERATOR OVERLOADING ====================================
    InventoryHolder operator+(const T &);
};

#endif