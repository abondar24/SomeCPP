//
// Created by abondar on 02.06.16.
//

#include <cstring>
#include "GridChar.h"


Grid<char*>::Grid(size_t inWidth, size_t inHeight ):width(inWidth), height(inHeight) {
    cells = new char**[width];
    for (size_t i = 0; i < width; i++) {
        cells[i] = new char*[height];
    }
}

Grid<char*>::Grid(const Grid<char*> &src) {
    copyFrom(src);
};

Grid<char*>::~Grid(){
    for (size_t i=0; i<width;i++){
        for (size_t j=0; j<height;j++){
            delete [] cells[i][j];
        }
    }
    delete [] cells;
    cells = nullptr;
};

void Grid<char*>::copyFrom(const Grid<char*>& src){
    width = src.width;
    height = src.height;
    cells = new char** [width];
    for (size_t i=0;i<width;i++){
        cells[i] = new char*[height];
    }

    for (size_t i=0;i<width;i++){
        for (size_t j=0;j<height;j++){
            if(src.cells[i][j]== nullptr){
                cells[i][j]= nullptr;
            } else{
                size_t len = strlen(src.cells[i][j])+1;
                cells[i][j] = new char[len];
                strncpy(cells[i][j],src.cells[i][j],len);
            }

        }
    }
}


Grid<char*>& Grid<char*>::operator=(const Grid<char*> &rhs){
    //self assign
    if (this == &rhs) {
        return *this;
    }

    //free mem
    for (int i = 0; i < width; i++) {
        for (int j;j<height;j++){
            delete[] cells[i][j];
        }
        delete[] cells[i];
    }
    delete[] cells;
    cells = nullptr;

    //reallocate
    copyFrom(rhs);

    return *this;
}

void Grid<char*>::setElementAt(size_t x, size_t y, const char *elem){
    delete [] cells[x][y];
    if (elem == nullptr){
        cells[x][y] = nullptr;
    } else {
        size_t  len = strlen(elem) +1;
        cells[x][y] = new char[len];
        strncpy(cells[x][y],elem,len);
    }
}

char* Grid<char*>::getElementAt(size_t x, size_t y) const{
    if (cells[x][y]== nullptr){
        return nullptr;
    }
    size_t len = strlen(cells[x][y]) +1;
    char* ret = new char[len];
    strncpy(ret,cells[x][y],len);
    return ret;
}

