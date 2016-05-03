//
// Created by abondar on 21.04.16.
//

#include <iostream>
#include "SpreadSheetCell.h"
#include <sstream>
using namespace std;


SpreadSheetCell::SpreadSheetCell(){
    val = 0;
    str = "";
}

SpreadSheetCell::SpreadSheetCell(double initVal){
    setValue(initVal);
}

SpreadSheetCell::SpreadSheetCell(const string& initVal){//pass by reference
    setString(initVal);
}

SpreadSheetCell::SpreadSheetCell(const SpreadSheetCell& src):
val(src.val),str(src.str){

}


void SpreadSheetCell::setValue(double inVal) {
    val = inVal;
    str = doubleToString(val);
}

void SpreadSheetCell::setString(string inStr) {
    str = inStr;
    val = stringToDouble(str);
}

double SpreadSheetCell::getValue() const {
    return val;
}

string SpreadSheetCell::getString() const {
    return str;
}

string SpreadSheetCell::doubleToString(double inVal) const {
    ostringstream ostr;
    ostr << inVal;

    return ostr.str();
}

double SpreadSheetCell::stringToDouble(string& inString) const {

    double  tmp;
    istringstream istr(inString);
    istr >> tmp;
    if (istr.fail() || !istr.eof()){
        return 0;
    }
    return tmp;
}



