//
// Created by abondar on 04.05.16.
//

#include "StringSpreadSheetCell.h"

StringSpreadSheetCell::StringSpreadSheetCell(): val("#NOVALUE") {
}

StringSpreadSheetCell::StringSpreadSheetCell(const DoubleSpreadSheetCell& doubleCell){
    val = doubleCell.getString();
}

void StringSpreadSheetCell::set(const string& str){
    val = str;
}

string StringSpreadSheetCell::getString() const { return val; }