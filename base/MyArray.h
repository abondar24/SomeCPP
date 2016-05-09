//
// Created by abondar on 08.05.16.
//

#ifndef SOMECPP_MYARRAY_H
#define SOMECPP_MYARRAY_H

#include <iostream>

using namespace std;

template<typename T>
class MyArray {
public:
    MyArray(size_t inSize) : size(inSize), mArray(nullptr) {
        mArray = new T[size];
    };

    virtual ~MyArray() {
        if (mArray) {
            delete[] mArray;
            mArray = nullptr;
        }
    };

    size_t getSize() const { return size; };

    T& at(size_t index) throw(std::out_of_range) {
        if (index >= 0 && index < getSize()) {
            return mArray[index];
        } else {
            throw std::out_of_range("MyArray::at: Index out of range");
        }
    };

protected:
    size_t size;
    T* mArray;
};


#endif //SOMECPP_MYARRAY_H
