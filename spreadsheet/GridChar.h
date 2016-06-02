//
// Created by abondar on 02.06.16.
//

#ifndef SOMECPP_GRIDCHAR_H
#define SOMECPP_GRIDCHAR_H

//spec template
#include "Grid.h"
template <>
class Grid<char*> {
public:
    Grid(size_t inWidth=defWidth,size_t inHeight = defHeight);
    Grid(const Grid<char*>& src);
    virtual ~Grid();
    Grid<char*>& operator=(const Grid<char*>& rhs);
    void setElementAt(size_t x, size_t y, const char* elem);
    char* getElementAt(size_t x, size_t y) const;
    size_t getHeight() const { return height;}
    size_t getWidth() const { return width;}

    static  const size_t  defWidth =10;
    static const size_t defHeight =10;


protected:
    void copyFrom(const Grid<char*>& src);

    char*** cells;
    size_t width;
    size_t height;

};


#endif //SOMECPP_GRIDCHAR_H
