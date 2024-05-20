#ifndef VECTORCLASS_H
#define VECTORCLASS_H

#include <iostream>
#include <stdexcept>
#include <limits>

template <typename T>
class vectorClass {
    T* arr;
    int capacity;
    int current;

public:
    // Destructor and Constructor
    vectorClass();
    ~vectorClass();
};
#endif // VECTORCLASS_H