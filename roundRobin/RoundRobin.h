//
// Created by abondar on 11.05.16.
//

#ifndef SOMECPP_ROUNDROBIN_H
#define SOMECPP_ROUNDROBIN_H

#include <stdexcept>
#include <vector>

template<typename T>
class RoundRobin {
public:
    RoundRobin(int numExpected = 0);

    virtual ~RoundRobin();

    void add(const T &elem);

    void remove(const T &elem);

    T& getNext() throw(std::out_of_range);

protected:
    std::vector<T> elems;
    typename std::vector<T>::iterator curElem;

private:
RoundRobin(const RoundRobin& src);
    RoundRobin& operator=(const RoundRobin& rhs);
};


template<typename T>
RoundRobin<T>::RoundRobin(int numExpected) {
    elems.reserve(numExpected);
    curElem = elems.begin();
}

template<typename T>
RoundRobin<T>::~RoundRobin() { }

template<typename T>
void RoundRobin<T>::add(const T &elem) {
    int pos = curElem - elems.begin();
    elems.push_back(elem);
    curElem = elems.begin() + pos;
}

template<typename T>
void RoundRobin<T>::remove(const T &elem){
    for (auto it = elems.begin(); it!=elems.end(); ++it){
        if (*it==elem){
            int newPos;
            if (curElem <= it){
                newPos = curElem - elems.begin();
            } else {
                newPos = curElem - elems.begin() -1;
            }
            elems.erase(it);
            curElem = elems.begin() + newPos;

            //in case if we removed last elem
            if (curElem == elems.end()){
                curElem = elems.begin();
            }
            return;
        }
    }
}

template<typename T>
T& RoundRobin<T>::getNext() throw(std::out_of_range){
    if (elems.empty()){
        throw  std::out_of_range("No elements in the list");
    }

    T& retVal = *curElem;
    ++curElem;
    if (curElem == elems.end()){
        curElem = elems.begin();
    }

    return retVal;
}



#endif //SOMECPP_ROUNDROBIN_H
