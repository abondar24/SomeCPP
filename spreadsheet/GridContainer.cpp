//
// Created by abondar on 09.06.16.
//

#include "GridContainer.h"

template <typename T,typename Container>
GridContainer<T,Container>::GridContainer(size_t inWidth,size_t inHeight ):
width(inWidth),height(inHeight){
    cells = new Container[width];
    for (size_t i=0;i<width;i++){
        cells[i].resize(height);
    }
};

template <typename T,typename Container>
GridContainer<T,Container>::GridContainer(const GridContainer<T,Container>& src){
    copyFrom(src);
};

template <typename T,typename Container>
GridContainer<T,Container>::~GridContainer(){
    delete []cells;
    cells = nullptr;
};

template <typename T,typename Container>
GridContainer<T,Container>& GridContainer<T,Container>::operator=(const GridContainer<T,Container>& rhs){
//self assign
    if (this == &rhs) {
        return *this;
    }


    delete[] cells;
    cells = nullptr;

    //reallocate
    copyFrom(rhs);

    return *this;
};

template <typename T,typename Container>
void GridContainer<T,Container>::setElementAt(int x, int y, const T& elem){
    cells[x][y]=elem;
};

template <typename T,typename Container>
const T& GridContainer<T,Container>::getElementAt(int x, int y) const{
    return cells[x][y];
};

template <typename T,typename Container>
void GridContainer<T,Container>::copyFrom(const GridContainer<T,Container>& src){
    width = src.getHeight();
    height = src.getWidth();
    cells = new Container [width];
    for (size_t i=0;i<width;i++){
        cells[i].resize[height];
    }

    for (size_t i=0;i<width;i++){
        for (size_t j=0;j<height;j++){
            cells[i][j] =src.getElementAt(i,j);
        }
    }
};