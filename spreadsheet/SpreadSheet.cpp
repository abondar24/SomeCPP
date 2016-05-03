//
// Created by abondar on 03.05.16.
//

#include "SpreadSheet.h"

SpreadSheet::SpreadSheet(const SpreadSheetApplication& app,int inWidth, int inHeight){
    impl = new SpreadSheetImpl(app,inWidth,inHeight);
}

SpreadSheet::SpreadSheet(const SpreadSheet& src){
    impl = new SpreadSheetImpl(*(src.impl));
}

SpreadSheet::SpreadSheet(const SpreadSheetApplication& app){
    impl = new SpreadSheetImpl(app);
}

SpreadSheet::~SpreadSheet(){
    delete impl;
    impl= nullptr;
}

SpreadSheet& SpreadSheet::operator=(const SpreadSheet& rc){
    *impl = *(rc.impl);
    return *this;
}

void SpreadSheet::setCellAt(int x, int y, const SpreadSheetCell& cell) {
    impl->setCellAt(x,y,cell);
}

SpreadSheetCell SpreadSheet::getCellAt(int x, int y) {

    return impl->getCellAt(x,y);
}

int SpreadSheet::getId() const {
    return impl->getId();
}