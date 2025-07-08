//
// Created by eljes on 08/07/2025.
//

#ifndef MYSET_H
#define MYSET_H
#pragma once

#include "OrderedArray.h"

template <typename T>
class MySet : public OrderedArray<T> {
    public:
    using OrderedArray<T>::OrderedArray;

    void push(const T& newElement) {
       if (this ->search(newElement) <0 ) {
           OrderedArray<T>:: push(newElement);
       }
    }

    MySet<T> operator|(const MySet<T>& other) const {
        MySet<T> result(this ->m_grow_size);
        for (int i = 0; i < this->length(); ++i) {
            result.push(this->getElement(i));
        }
        for (int i = 0; i < other.length(); ++i) {
            result.push(other.getElement(i));
        }
        return result;
    }
    MySet<T> operator&(const MySet<T>& other) const {
        MySet<T> result(this->m_grow_size);
        for (int i = 0; i < this->length(); ++i) {
           T element = this->getElement(i);
             if (other.search(element) >= 0) {
                result.push(element);
        }
        return result;
    }
        int search(const string & string);
}

    int search(const string & string);



