//
// Created by abondar on 04.05.16.
//

#ifndef SOMECPP_SPREADSHEETCELL_H
#define SOMECPP_SPREADSHEETCELL_H

#include <string>

using std::string;

//abstract class
class SpreadSheetCell {
public:
    SpreadSheetCell();

    virtual ~SpreadSheetCell();

    virtual void set(const std::string& str) = 0;
    virtual std::string getString() const =0;
};


#endif //SOMECPP_SPREADSHEETCELL_H
