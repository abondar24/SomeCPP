//
// Created by abondar on 30.05.16.
//

#ifndef SOMECPP_GRID_H
#define SOMECPP_GRID_H

#include <iostream>
using namespace std;
template<typename T>

class Grid {
public:
    Grid(size_t inWidth=defWidth,size_t inHeight = defHeight);
    Grid(const Grid<T>& src);
    virtual ~Grid();
    Grid<T>& operator=(const Grid<T>& rhs);
    void setElementAt(int x, int y, const T& elem);
    const T& getElementAt(int x, int y) const;
    size_t getHeight() const { return height;}
    size_t getWidth() const { return width;}

    static  const size_t  defWidth =10;
    static const size_t defHeight =10;


protected:
    void copyFrom(const Grid<T>& src);
    T** cells;
    size_t width;
    size_t height;



};


#endif //SOMECPP_GRID_H
