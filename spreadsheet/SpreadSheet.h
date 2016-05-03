//
// Created by abondar on 03.05.16.
//

#ifndef SOMECPP_SPREADSHEED_H
#define SOMECPP_SPREADSHEED_H

#include "SpreadSheetCell.h"
#include "SpreadSheetImpl.h"

//interface
class SpreaSheetImpl;
class SpreadSheetApplication;
class SpreadSheet {

public:
    SpreadSheet(const SpreadSheetApplication& app,int inWidth, int inHeight);
    SpreadSheet(const SpreadSheet& src);
    SpreadSheet(const SpreadSheetApplication& app);
    ~SpreadSheet();
    SpreadSheet& operator=(const SpreadSheet& rc);
    void setCellAt(int x, int y, const SpreadSheetCell &cell);
    SpreadSheetCell getCellAt(int x, int y);
    int getId() const;

protected:
    SpreadSheetImpl* impl;
};


#endif //SOMECPP_SPREADSHEED_H
