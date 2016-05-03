//
// Created by abondar on 03.05.16.
//

#include <stdexcept>
#include "SpreadSheet.h"


SpreadSheet::SpreadSheet(int inWidth, int inHeight):
width(inWidth),height(inHeight){
    cells = new SpreadSheetCell* [width];

    for (int i =0;i<width;i++){
        cells[i]= new SpreadSheetCell[height];
    }
}

SpreadSheet::SpreadSheet(const SpreadSheet &src) {
   copyFrom(src);
}

SpreadSheet&  SpreadSheet::operator=(const SpreadSheet& rhs){

    //self assign
    if (this == &rhs){
        return *this;
    }

    //free mem
    for (int i=0;i<width;i++){
        delete[] cells[i];
    }
    delete[] cells;
    cells = nullptr;

    //reallocate
    copyFrom(rhs);

    return  *this;
}

void SpreadSheet:: copyFrom(const SpreadSheet& src){
    width = src.width;
    height = src.height;
    cells = new SpreadSheetCell* (width);

    for (int i=0; i<width;i++){
        cells[i] = new SpreadSheetCell[height];
    }

    for (int i=0; i<width;i++){
        for (int j = 0; j < height; ++j) {
            cells[i][j] = src.cells[i][j];
        }
    }

}

void SpreadSheet::setCellAt(int x, int y, const SpreadSheetCell &cell) {
    if (!inRange(x,width) || !inRange(y,height)){

        throw std::out_of_range("");
    }

    cells[x][y]=cell;
}

SpreadSheetCell SpreadSheet::getCellAt(int x, int y) {
    if (!inRange(x,width) || !inRange(y,height)){

        throw std::out_of_range("");
    }
    return cells[x][y];
}


bool SpreadSheet::inRange(int val, int upper)
{
    return (val >= 0 && val < upper);
}


SpreadSheet ::~SpreadSheet() {
    for (int i=0;i<width;i++){
        delete[] cells[i];
    }

    delete[] cells;

    cells = nullptr;
}