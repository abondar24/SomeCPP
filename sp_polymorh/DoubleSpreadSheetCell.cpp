//
// Created by abondar on 04.05.16.
//

#include "DoubleSpreadSheetCell.h"
#include <sstream>
#include <iostream>
using namespace std;

DoubleSpreadSheetCell::DoubleSpreadSheetCell(): val(-1) { }

void DoubleSpreadSheetCell::set(double doub) {
    val = doub;
}

void DoubleSpreadSheetCell::set(const string& strVal){
    val = stringToDouble(strVal);
}

string DoubleSpreadSheetCell::getString() const {
    return doubleToString(val);
}

string  DoubleSpreadSheetCell::doubleToString(double inVal)  {
    ostringstream ostr;
    ostr << inVal;

    return ostr.str();
}

double  DoubleSpreadSheetCell::stringToDouble(const string& inString)  {

    double  tmp;
    istringstream istr(inString);
    istr >> tmp;
    if (istr.fail() || !istr.eof()){
        return 0;
    }
    return tmp;
}