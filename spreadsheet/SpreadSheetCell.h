//
// Created by abondar on 21.04.16.
//

#ifndef SOMECPP_SPREADSHEETCELL_H
#define SOMECPP_SPREADSHEETCELL_H

#include <string>

using std::string;

class SpreadSheetCell {

public:

    SpreadSheetCell();
    SpreadSheetCell(double initVal);
    SpreadSheetCell(const SpreadSheetCell& src);//copy constructor
    SpreadSheetCell(const string& initVal);

    void setValue(double inVal);
    double getValue() const;

    void setString(string inStr);
    string getString() const;

protected:
    string doubleToString(double inVal) const;
    double stringToDouble(string& inString) const;

    double val;
    string str;

};


#endif //SOMECPP_SPREADSHEETCELL_H
