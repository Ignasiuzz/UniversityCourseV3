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

    // Member functions
    vectorClass(const vectorClass& other); // Copy constructor
    vectorClass& operator=(const vectorClass& other); // Copy assignment
    vectorClass(vectorClass&& other) noexcept; // Move constructor
    vectorClass& operator=(vectorClass&& other) noexcept; // Move assignment
};
#endif // VECTORCLASS_H