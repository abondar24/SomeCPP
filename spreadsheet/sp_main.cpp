//
// Created by abondar on 22.04.16.
//
#include <iostream>
#include "SpreadSheetCell.h"
#include "SpreadSheet.h"
using namespace std;

int main() {
    SpreadSheetCell cell1(4), cell2(3); //stack constr

    cout << "cell1 " << cell1.getValue() << endl;
    cout << "cell2 " << cell2.getValue() << endl;

    //heap
    SpreadSheetCell *cell3 = new SpreadSheetCell(7);
    cout << "cell3 " << cell3->getValue() << endl;
    delete cell3;

    SpreadSheetCell cell4("test");
    cout << "cell4 " << cell4.getString() << endl;

    SpreadSheetCell cell5;
    cell5.setValue(5.6);
    cout << "cell5 " << cell5.getValue() << endl;

    SpreadSheetCell cell6(cell1);
    cout << "cell6 " << cell6.getValue() << endl;


    return 0;
}