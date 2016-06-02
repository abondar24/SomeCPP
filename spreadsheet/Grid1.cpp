//
// Created by abondar on 01.06.16.
//

#include "Grid1.h"

template<typename T, size_t WIDTH,size_t HEIGHT>
template<typename E, size_t WIDTH1,size_t HEIGHT1>
Grid1<T,WIDTH,HEIGHT>::Grid1(const Grid1<E,WIDTH1, HEIGHT1>& src){
    copyFrom(src);
};


template<typename T, size_t WIDTH,size_t HEIGHT>
void Grid1<T,WIDTH,HEIGHT>::setElementAt(int x, int y, const T& elem){
    cells[x][y]=elem;
};

template<typename T, size_t WIDTH,size_t HEIGHT>
T& Grid1<T,WIDTH,HEIGHT>::getElementAt(int x, int y) {
    return cells[x][y];
};

template<typename T, size_t WIDTH,size_t HEIGHT>
const T& Grid1<T,WIDTH,HEIGHT>::getElementAt(int x, int y) const {
    return cells[x][y];
};

template<typename T, size_t WIDTH,size_t HEIGHT>
template<typename E, size_t WIDTH1,size_t HEIGHT1>
Grid1<T,WIDTH,HEIGHT>& Grid1<T,WIDTH,HEIGHT>::operator=(const Grid1<E,WIDTH1,HEIGHT1>& rhs){
    copyFrom(rhs);
    return *this;
};

template<typename T, size_t WIDTH,size_t HEIGHT>
template<typename E, size_t WIDTH1,size_t HEIGHT1>
void Grid1<T,WIDTH,HEIGHT>::copyFrom(const Grid1<E,WIDTH1,HEIGHT1>& src){
    for (size_t i=0; i<WIDTH;i++){
        for (size_t j=0; j<HEIGHT;j++){
            if ( i < WIDTH1 && j<HEIGHT1){
                cells[i][j] = src.getElementAt(i,j);
            }    else {
                cells[i][j] = T();
            }
        }

    }
};


