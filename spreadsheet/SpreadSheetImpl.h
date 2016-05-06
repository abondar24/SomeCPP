//
// Created by abondar on 03.05.16.
//

#ifndef SOMECPP_SPREADSHEET_H
#define SOMECPP_SPREADSHEET_H

#include "SpreadSheetCell.h"

class SpreadSheetApplication; //forward declaration
class SpreadSheetImpl {
public:
    SpreadSheetImpl(const SpreadSheetApplication& app,int inWidth =maxWidth, int inHeight=maxHeight);
    SpreadSheetImpl(const SpreadSheetImpl& src);
    SpreadSheetImpl(SpreadSheetImpl&& src);
    ~SpreadSheetImpl();
    SpreadSheetImpl& operator=(const SpreadSheetImpl& rc);
    SpreadSheetImpl& operator=(SpreadSheetImpl&& rc);

    void setCellAt(int x, int y, const SpreadSheetCell& cell);
    SpreadSheetCell getCellAt(int x, int y);
    int getId() const;

    static const int maxHeight = 100;
    static const int maxWidth = 100;

protected:
    bool inRange(int val, int upper);
    void copyFrom(const SpreadSheetImpl& src);

    int width, height;
    SpreadSheetCell **cells; //for allocating 2-dim arrays
    static int counter;
    int id;
    const SpreadSheetApplication& app;

};


#endif //SOMECPP_SPREADSHEET_H
