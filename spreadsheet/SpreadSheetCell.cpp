//
// Created by abondar on 21.04.16.
//

#include <iostream>
#include "SpreadSheetCell.h"
#include <sstream>
using namespace std;


SpreadSheetCell::SpreadSheetCell() {
    val = 0;
    str = "";
    numAccesses =0;
}

SpreadSheetCell::SpreadSheetCell(double initVal){
    set(initVal);
}

SpreadSheetCell::SpreadSheetCell(const string& initVal){//pass by reference
    set(initVal);
}

SpreadSheetCell::SpreadSheetCell(const SpreadSheetCell& src):
val(src.val),str(src.str){

}


void SpreadSheetCell::set(double inVal) {
    val = inVal;
    str = doubleToString(val);
}

void SpreadSheetCell::set(const string& inStr) {
    str = inStr;
    val = stringToDouble(str);
}


string SpreadSheetCell::doubleToString(double inVal)  {
    ostringstream ostr;
    ostr << inVal;

    return ostr.str();
}

double SpreadSheetCell::stringToDouble(string& inString)  {

    double  tmp;
    istringstream istr(inString);
    istr >> tmp;
    if (istr.fail() || !istr.eof()){
        return 0;
    }
    return tmp;
}

void SpreadSheetCell::setColor(Colors color){
    mColor =color;
};

bool SpreadSheetCell::checkSpreadSheetCell(const SpreadSheetCell& cell){
    return !(cell.str.empty());
}

const SpreadSheetCell operator+(const SpreadSheetCell& lc,const SpreadSheetCell& rc) {
    SpreadSheetCell newCell;
    newCell.set(lc.val+rc.val);
    return newCell;
}

const SpreadSheetCell operator*(const SpreadSheetCell& lc,const SpreadSheetCell& rc)  {
    SpreadSheetCell newCell;
    newCell.set(lc.val*rc.val);
    return newCell;
}

const SpreadSheetCell operator-(const SpreadSheetCell& lc,const SpreadSheetCell& rc) {
    SpreadSheetCell newCell;
    newCell.set(lc.val-rc.val);
    return newCell;
}

const SpreadSheetCell operator/(const SpreadSheetCell& lc,const SpreadSheetCell& rc) {
    if (rc.val==0){
        throw invalid_argument("Divide by zero");
    }
    SpreadSheetCell newCell;
    newCell.set(lc.val/rc.val);
    return newCell;
}


bool operator==(const SpreadSheetCell& lc, const SpreadSheetCell& rc){
    return (lc.val==rc.val);
}

bool operator>(const SpreadSheetCell& lc, const SpreadSheetCell& rc){
    return (lc.val>rc.val);
}

bool operator<(const SpreadSheetCell& lc, const SpreadSheetCell& rc){
    return (lc.val<rc.val);
}

bool operator!=(const SpreadSheetCell& lc, const SpreadSheetCell& rc){
    return (lc.val!=rc.val);
}

bool operator>=(const SpreadSheetCell& lc, const SpreadSheetCell& rc){
    return (lc.val>=rc.val);
}

bool operator<=(const SpreadSheetCell& lc, const SpreadSheetCell& rc){
    return (lc.val<=rc.val);
}

SpreadSheetCell& SpreadSheetCell::operator+=(const SpreadSheetCell& rc){
    set(val+rc.val);
    return *this;
}

SpreadSheetCell& SpreadSheetCell::operator-=(const SpreadSheetCell& rc){
    set(val-rc.val);
    return *this;
}

SpreadSheetCell& SpreadSheetCell::operator*=(const SpreadSheetCell& rc){
    set(val*rc.val);
    return *this;
}

SpreadSheetCell& SpreadSheetCell::operator/=(const SpreadSheetCell& rc){
    if (rc.val==0){
        throw invalid_argument("Divide by zero");
    }
    set(val/rc.val);
    return *this;
}

