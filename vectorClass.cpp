#include "vectorClass.h"

// Default constructor
template <typename T>
vectorClass<T>::vectorClass() : arr(new T[1]), capacity(1), current(0) {}

// Destructor
template <typename T>
vectorClass<T>::~vectorClass() {
    delete[] arr;
}

// Copy constructor
template <typename T>
vectorClass<T>::vectorClass(const vectorClass& other) : capacity(other.capacity), current(other.current) {
    arr = new T[capacity];
    for (int i = 0; i < current; i++) {
        arr[i] = other.arr[i];
    }
}

// Copy assignment operator
template <typename T>
vectorClass<T>& vectorClass<T>::operator=(const vectorClass& other) {
    if (this != &other) {
        delete[] arr;
        capacity = other.capacity;
        current = other.current;
        arr = new T[capacity];
        for (int i = 0; i < current; i++) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

// Move constructor
template <typename T>
vectorClass<T>::vectorClass(vectorClass&& other) noexcept : arr(other.arr), capacity(other.capacity), current(other.current) {
    other.arr = nullptr;
    other.capacity = 0;
    other.current = 0;
}

// Move assignment operator
template <typename T>
vectorClass<T>& vectorClass<T>::operator=(vectorClass&& other) noexcept {
    if (this != &other) {
        delete[] arr;
        arr = other.arr;
        capacity = other.capacity;
        current = other.current;
        other.arr = nullptr;
        other.capacity = 0;
        other.current = 0;
    }
    return *this;
}