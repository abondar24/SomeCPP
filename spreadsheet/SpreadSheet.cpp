//
// Created by abondar on 03.05.16.
//

#include <stdexcept>
#include "SpreadSheet.h"

int SpreadSheet::counter = 0;

SpreadSheet::SpreadSheet( int inWidth, int inHeight) :
        width(inWidth < maxWidth ? inWidth : maxWidth),
        height(inHeight < maxHeight ? inHeight : maxHeight){
    id = counter++;
    cells = new SpreadSheetCell *[width];

    for (int i = 0; i < width; i++) {
        cells[i] = new SpreadSheetCell[height];
    }
}

SpreadSheet::SpreadSheet(const SpreadSheet &src)  {
    id = counter++;
    copyFrom(src);
}

SpreadSheet::SpreadSheet(SpreadSheet &&src)  {
    width = src.width;
    height = src.height;
    cells = src.cells;
    src.width = 0;
    src.height = 0;
    src.cells = nullptr;
}


SpreadSheet& SpreadSheet::operator=(const SpreadSheet &rc) {

    //self assign
    if (this == &rc) {
        return *this;
    }

    //free mem
    for (int i = 0; i < width; i++) {
        delete[] cells[i];
    }
    delete[] cells;
    cells = nullptr;

    //reallocate
    copyFrom(rc);

    return *this;
}

SpreadSheet& SpreadSheet::operator=(SpreadSheet&& rc){
    if (this == &rc) {
        return *this;
    }
    for (int i = 0; i < width; i++) {
        delete[] cells[i];
    }
    delete[] cells;


    width =rc.width;
    height = rc.height;
    cells = rc.cells;

    rc.width=0;
    rc.height=0;
    rc.cells= nullptr;
    return *this;

}


void SpreadSheet::copyFrom(const SpreadSheet &src) {
    width = src.width;
    height = src.height;
    cells = new SpreadSheetCell *[width];

    for (int i = 0; i < width; i++) {
        cells[i] = new SpreadSheetCell[height];
    }

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; ++j) {
            cells[i][j] = src.cells[i][j];
        }
    }

}

void SpreadSheet::setCellAt(int x, int y, const SpreadSheetCell &cell) {
    if (!inRange(x, width) || !inRange(y, height)) {

        throw std::out_of_range("");
    }

    cells[x][y] = cell;
}

SpreadSheetCell SpreadSheet::getCellAt(int x, int y) {
    if (!inRange(x, width) || !inRange(y, height)) {

        throw std::out_of_range("");
    }
    return cells[x][y];
}

int SpreadSheet::getId() const {
    return id;
}


bool SpreadSheet::inRange(int val, int upper) {
    return (val >= 0 && val < upper);
}


SpreadSheet::~SpreadSheet() {
    for (int i = 0; i < width; i++) {
        delete[] cells[i];
    }

    delete[] cells;

    cells = nullptr;
}