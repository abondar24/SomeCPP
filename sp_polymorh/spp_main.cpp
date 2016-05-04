//
// Created by abondar on 04.05.16.
//

#include "SpreadSheetCell.h"
#include "StringSpreadSheetCell.h"

#include <iostream>

using namespace std;

int main() {
    SpreadSheetCell *cellArray[3];

    cellArray[0] = new StringSpreadSheetCell();
    cellArray[1] = new StringSpreadSheetCell();
    cellArray[2] = new DoubleSpreadSheetCell();

    cellArray[0]->set("hi");
    cellArray[1]->set("1");
    cellArray[2]->set("2");

    cout << "Array values are[" << cellArray[0]->getString() << "," <<
    cellArray[1]->getString() << "," <<
    cellArray[2]->getString() << "]" << endl;

    return 0;
};