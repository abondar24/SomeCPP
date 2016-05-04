//
// Created by abondar on 04.05.16.
//

#ifndef SOMECPP_STRINGSPREADSHEETCELL_H
#define SOMECPP_STRINGSPREADSHEETCELL_H
#include <string>
#include "SpreadSheetCell.h"
#include "DoubleSpreadSheetCell.h"

using std::string;


class StringSpreadSheetCell : public SpreadSheetCell {
public:
    StringSpreadSheetCell();
    StringSpreadSheetCell(const DoubleSpreadSheetCell& doubleCell);

    virtual void set(const std::string& str);
    virtual std::string getString() const;

protected:
    std::string val;
};


#endif //SOMECPP_STRINGSPREADSHEETCELL_H
