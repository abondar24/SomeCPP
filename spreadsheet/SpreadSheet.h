//
// Created by abondar on 03.05.16.
//

#ifndef SOMECPP_SPREADSHEET_H
#define SOMECPP_SPREADSHEET_H

#include "SpreadSheetCell.h"


class SpreadSheet {
public:
    SpreadSheet(int inWidth =maxWidth, int inHeight=maxHeight);
    SpreadSheet(const SpreadSheet& src);
    SpreadSheet(SpreadSheet&& src);
    ~SpreadSheet();
    SpreadSheet& operator=(const SpreadSheet& rc);
    SpreadSheet& operator=(SpreadSheet&& rc);

    void setCellAt(int x, int y, const SpreadSheetCell& cell);
    SpreadSheetCell getCellAt(int x, int y);
    int getId() const;

    static const int maxHeight = 100;
    static const int maxWidth = 100;

protected:
    bool inRange(int val, int upper);
    void copyFrom(const SpreadSheet& src);

    int width, height;
    SpreadSheetCell **cells; //for allocating 2-dim arrays
    static int counter;
    int id;

};


#endif //SOMECPP_SPREADSHEET_H
