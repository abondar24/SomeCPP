//
// Created by abondar on 03.05.16.
//

#include <stdexcept>
#include "SpreadSheetImpl.h"

int SpreadSheetImpl::counter = 0;

SpreadSheetImpl::SpreadSheetImpl(const SpreadSheetApplication &app, int inWidth, int inHeight) :
        width(inWidth < maxWidth ? inWidth : maxWidth),
        height(inHeight < maxHeight ? inHeight : maxHeight),
        app(app) {
    id = counter++;
    cells = new SpreadSheetCell *[width];

    for (int i = 0; i < width; i++) {
        cells[i] = new SpreadSheetCell[height];
    }
}

SpreadSheetImpl::SpreadSheetImpl(const SpreadSheetImpl &src) :
        app(src.app) {
    id = counter++;
    copyFrom(src);
}

SpreadSheetImpl::SpreadSheetImpl(SpreadSheetImpl &&src) : app(src.app) {
    width = src.width;
    height = src.height;
    cells = src.cells;
    src.width = 0;
    src.height = 0;
    src.cells = nullptr;
}


SpreadSheetImpl& SpreadSheetImpl::operator=(const SpreadSheetImpl &rc) {

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

SpreadSheetImpl& SpreadSheetImpl::operator=(SpreadSheetImpl&& rc){
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


void SpreadSheetImpl::copyFrom(const SpreadSheetImpl &src) {
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

void SpreadSheetImpl::setCellAt(int x, int y, const SpreadSheetCell &cell) {
    if (!inRange(x, width) || !inRange(y, height)) {

        throw std::out_of_range("");
    }

    cells[x][y] = cell;
}

SpreadSheetCell SpreadSheetImpl::getCellAt(int x, int y) {
    if (!inRange(x, width) || !inRange(y, height)) {

        throw std::out_of_range("");
    }
    return cells[x][y];
}

int SpreadSheetImpl::getId() const {
    return id;
}


bool SpreadSheetImpl::inRange(int val, int upper) {
    return (val >= 0 && val < upper);
}


SpreadSheetImpl::~SpreadSheetImpl() {
    for (int i = 0; i < width; i++) {
        delete[] cells[i];
    }

    delete[] cells;

    cells = nullptr;
}