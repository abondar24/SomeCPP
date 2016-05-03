//
// Created by abondar on 03.05.16.
//

#ifndef SOMECPP_SPREADSHEET_H
#define SOMECPP_SPREADSHEET_H

#include "SpreadSheetCell.h"

class SpreadSheet {
public:
    SpreadSheet(int inWidth, int inHeight);
    ~SpreadSheet();

    void setCellAt(int x, int y, const SpreadSheetCell &cell);
    void copyFrom(const SpreadSheet& src);

    SpreadSheetCell getCellAt(int x, int y);

protected:
    bool inRange(int val,int upper);
    int width,height;
    SpreadSheetCell** cells; //for allocating 2-dim arrays
    static int counter=0;

private:
    SpreadSheet(const SpreadSheet& src);
    SpreadSheet& operator=(const SpreadSheet& rhs);

};


#endif //SOMECPP_SPREADSHEET_H
