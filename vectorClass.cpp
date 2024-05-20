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

// Assigns values to the container 
template <typename T>
void vectorClass<T>::assign(int n, const T& val) {
    clear(); // Clear the current contents
    if (capacity < n) {
        reserve(n); // Reserve enough space if needed
    }
    for (int i = 0; i < n; ++i) {
        push_back(val); // Add n copies of val
    }
}

// Function to get element at index
template <typename T>
T& vectorClass<T>::at(int index) {
    if (index < 0 || index >= current) {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}
template <typename T>
const T& vectorClass<T>::at(int index) const {
    if (index < 0 || index >= current) {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}

// operator[] for accessing elements
template <typename T>
T& vectorClass<T>::operator[](int index) {
    return arr[index];
}
template <typename T>
const T& vectorClass<T>::operator[](int index) const {
    return arr[index];
}

// Function to get front element
template <typename T>
T& vectorClass<T>::front() {
    if (empty()) {
        throw std::out_of_range("Vector is empty");
    }
    return arr[0];
}
template <typename T>
const T& vectorClass<T>::front() const {
    if (empty()) {
        throw std::out_of_range("Vector is empty");
    }
    return arr[0];
}

// Function to get back element
template <typename T>
T& vectorClass<T>::back() {
    if (empty()) {
        throw std::out_of_range("Vector is empty");
    }
    return arr[current - 1];
}
template <typename T>
const T& vectorClass<T>::back() const {
    if (empty()) {
        throw std::out_of_range("Vector is empty");
    }
    return arr[current - 1];
}

// Function to check if the vector is empty
template <typename T>
bool vectorClass<T>::empty() const {
    return current == 0;
}

// Function to get size of the vector
template <typename T>
int vectorClass<T>::size() const {
    return current;
}

// Function to get the maximum size of the vector
template <typename T>
int vectorClass<T>::max_size() const {
    return std::numeric_limits<int>::max();
}

// Function to reserve capacity
template <typename T>
void vectorClass<T>::reserve(int new_capacity) {
    if (new_capacity > capacity) {
        T* temp = new T[new_capacity];
        for (int i = 0; i < current; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        capacity = new_capacity;
    }
}

// Function to get capacity of the vector
template <typename T>
int vectorClass<T>::get_capacity() const {
    return capacity;
}

// Function to shrink capacity to fit size
template <typename T>
void vectorClass<T>::shrink_to_fit() {
    if (current < capacity) {
        T* temp = new T[current];
        for (int i = 0; i < current; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        capacity = current;
    }
}