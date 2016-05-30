//
// Created by abondar on 31.05.16.
//

#include "Grid.h"

template <typename T>
Grid<T>::Grid(size_t inWidth,size_t inHeight ): width(inWidth),height(inHeight){
    cells = new T* [width];
    for (size_t i=0;i<width;i++){
        cells[i] = new T[height];
    }
}

template <typename T>
Grid<T>::Grid(const Grid<T>& src){
copyFrom(src);
}

template <typename T>
Grid<T>::~Grid(){
    for (size_t i=0; i<width;i++){
        delete [] cells[i];
    }
    delete [] cells;
    cells = nullptr;
}

template <typename T>
void Grid<T>::copyFrom(const Grid<T>& src){
    width = src.width;
    height = src.height;
    cells = new T* [width];
    for (size_t i=0;i<width;i++){
        cells[i] = new T[height];
    }

    for (size_t i=0;i<width;i++){
        for (size_t j=0;j<height;j++){
           cells[i][j] =src.cells[i][j];
        }
    }
}

template <typename T>
Grid<T>& Grid<T>::operator=(const Grid<T>& rhs){
    //self assign
    if (this == &rhs) {
        return *this;
    }

    //free mem
    for (int i = 0; i < width; i++) {
        delete[] cells[i];
    }
    delete[] cells;
    cells = nullptr;

    //reallocate
    copyFrom(rhs);

    return *this;
}

template <typename T>
void Grid<T>::setElementAt(int x, int y, const T& elem){
 cells[x][y] =elem;
}

template <typename T>
const T& Grid<T>::getElementAt(int x, int y) const{
    return  cells[x][y];
}