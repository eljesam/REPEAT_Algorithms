 #pragma once
#include <algorithm>
#include <array>
#include <cstddef>
#include <stdexcept>
#include <utility>

using namespace std;

 void reserve(int m_grow_size);

 int new_capacity;

 int element;

template <typename T>

class OrderedArray {
    T* m_array;
    int m_size;
    int m_capacity;
    int m_grow_size;

public :
    OrderedArray(int grow_size): m_array(nullptr), m_size(0), m_capacity(0), m_grow_size(grow_size > 0 ? grow_size : 8) {
    reserve (m_grow_size);
}

    ~OrderedArray() {
    delete[] m_array;
}

    void push(const T& newElement) {
    if (m_size >= m_capacity) {
        reserve(m_grow_size + m_capacity);

        int pos = 0;
        while (pos < m_size && m_array[pos] < newElement) {
            pos++;
        }
        for (int i = m_size; i > pos; --i) {
            m_array[i] = m_array[i - 1];
        }
        m_array[pos] = newElement;
        m_size++;
    }

}

    int length() const {
    return m_size;
}
    T getElement(int index) const {
    if (index < 0 || index >= m_size) {
        return T{};
    }
    return m_array[index];
}
    bool remove (int index){
    if (index < 0 || index >= m_size) {
        return false;

        for (int i = index; i < m_size - 1; ++i) {
            m_array[i] = m_array[i + 1];

        }
        m_size--;
        return true;
    }
    int search(const T& element); {
        int left = 0;
        int right = m_size - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (m_array[middle] == element) {
                return middle;
            }
            else if (m_array[middle] < element) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        return -1;
    }
    void clear();{
        m_size = 0;
    }
    private:
    void reserve(int new_capacity); {
        if (new_capacity <= m_capacity) {
            return;
        }
        T* new_array = new T[new_capacity];
        for (int i = 0; i < m_size; ++i) {
            new_array[i] = move(m_array[i]);
        }
        delete[] m_array;
        m_array = new_array;
        m_capacity = new_capacity;
    }
}
};



