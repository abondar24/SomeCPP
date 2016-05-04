//
// Created by abondar on 04.05.16.
//

#ifndef SOMECPP_DOUBLESPREADSHEETCELL_H
#define SOMECPP_DOUBLESPREADSHEETCELL_H


#include "SpreadSheetCell.h"

class DoubleSpreadSheetCell: public SpreadSheetCell {
public:
    DoubleSpreadSheetCell();
    virtual void set(double doub);
    virtual void set(const std::string& str);
    virtual std::string getString() const;

protected:
    static std::string doubleToString(double dVal);
    static double stringToDouble(const std::string& strVal);
    double val;

};


#endif //SOMECPP_DOUBLESPREADSHEETCELL_H
