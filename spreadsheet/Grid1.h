//
// Created by abondar on 01.06.16.
//

#ifndef SOMECPP_GRID1_H
#define SOMECPP_GRID1_H

#include <iostream>
using namespace std;
//non-type template params
template<typename T, size_t WIDTH=10,size_t HEIGHT=10>
class Grid1 {
public:
    Grid1(){};

    template<typename E, size_t WIDTH1,size_t HEIGHT1>
    Grid1(const Grid1<E,WIDTH1,HEIGHT1>& src);

    template<typename E, size_t WIDTH1,size_t HEIGHT1>
    Grid1<T,WIDTH,HEIGHT>&operator=(const Grid1<E,WIDTH1,HEIGHT1>& rhs);

    void setElementAt(int x, int y, const T& elem);
    T& getElementAt(int x, int y) ;
    const T& getElementAt(int x, int y) const;

    size_t getHeight() const { return HEIGHT;}
    size_t getWidth() const { return WIDTH;}

    static  const size_t  defWidth =10;
    static const size_t defHeight =10;


protected:
    template<typename E, size_t WIDTH1,size_t HEIGHT1>
    void copyFrom(const Grid1<E,WIDTH1,HEIGHT1>& src);

    T cells[WIDTH][HEIGHT];



};


#endif //SOMECPP_GRID1_H
