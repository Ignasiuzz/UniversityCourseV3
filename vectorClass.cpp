#include "vectorClass.h"

// Default constructor
template <typename T>
vectorClass<T>::vectorClass() : arr(new T[1]), capacity(1), current(0) {}

// Destructor
template <typename T>
vectorClass<T>::~vectorClass() {
    delete[] arr;
}
