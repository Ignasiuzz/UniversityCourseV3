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
    void assign(int n, const T& val);
    /* Truksta assing_range, get_allocator */

    // Element access
    T& at(int index);
    const T& at(int index) const;
    T& operator[](int index);
    const T& operator[](int index) const;
};
#endif // VECTORCLASS_H