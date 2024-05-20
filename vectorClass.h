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
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    /* Truksta data */

    // Iterators
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    iterator begin() noexcept { return arr; }
    const_iterator begin() const noexcept { return arr; }
    iterator end() noexcept { return arr + current; }
    const_iterator end() const noexcept { return arr + current; }
    reverse_iterator rbegin() noexcept { return reverse_iterator(end()); }
    const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(end()); }
    reverse_iterator rend() noexcept { return reverse_iterator(begin()); }
    const_reverse_iterator rend() const noexcept { return const_reverse_iterator(begin()); }

    // Capacity
    bool empty() const;
    int size() const;
    int max_size() const;
    void reserve(int new_capacity);
    int get_capacity() const;
    void shrink_to_fit();

    // Modifiers
    void clear();
    void insert(int index, T data);
    void erase(int index);
    void push_back(T data);
    void pop_back();
    void resize(int new_size);
    void swap(vectorClass<T>& other);
    /* Truksta insert_range, append_range, emplace, emplace_back */

    /* Isviso truksta: assing_range, get_allocator, data, insert_range, append_range, emplace, emplace_back */
    /* Realizuota 25 is 32 funciju, kas yra 78% */
};
#endif // VECTORCLASS_H