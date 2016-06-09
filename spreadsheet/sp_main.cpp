//
// Created by abondar on 22.04.16.
//
#include <iostream>
#include "SpreadSheetCell.h"
#include "SpreadSheet.h"
#include "Grid.cpp"
#include "Grid1.cpp"
#include "GridChar.h"

#include <vector>
#include "GridContainer.cpp"

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
    cell5.set(5.6);
    cout << "cell5 " << cell5.getValue() << endl;

    SpreadSheetCell cell6(cell1);
    cell6.setColor(SpreadSheetCell::Blue);
    cout << "cell6 " << cell6.getValue() << endl;

    SpreadSheetCell cell7=cell6+cell5;
    cout << "cell7 " << cell7.getValue() << endl;

    SpreadSheetCell cell8=cell2*cell5;
    cout << "cell8 " << cell8.getValue() << endl;
    SpreadSheetCell cell9=cell1-cell2;
    cout << "cell9 " << cell9.getValue() << endl;

    SpreadSheetCell cell10=cell5/cell2;
    cout << "cell10 " << cell10.getValue() << endl;

    SpreadSheetCell cell11=cell5+5;
    cout << "cell11 " << cell11.getValue() << endl;

    SpreadSheetCell cell12=3+7;
    cout << "cell12 " << cell12.getValue() << endl;

    SpreadSheetCell cell13=5*cell1;
    cout << "cell13 " << cell13.getValue() << endl;

    SpreadSheetCell cell14;
    cell14 += cell1;
    cout << "cell14 " << cell14.getValue() << endl;

    SpreadSheetCell cell15;
    cell15-=5;
    cout << "cell15 " << cell15.getValue() << endl;

    bool res =  cell8 > cell1;
    cout << res << endl;

    res =  cell5 <= cell1;
    cout << res << endl;

     res =  cell4 == cell1;
    cout << res << endl;


    Grid<int> intGrid;
    Grid<double> doubleGrid(11,11);
    intGrid.setElementAt(1,1,7);

    int x = intGrid.getElementAt(1,1);
    cout << "x(1,1) " << x << endl;

    Grid<SpreadSheetCell> spreadSheet;
    SpreadSheetCell spreadSheetCell;
    spreadSheet.setElementAt(6,5,spreadSheetCell);

    Grid1<int,10,10>grid;
    grid.setElementAt(1,1,45);
    cout << grid.getElementAt(1,1) << endl;

    Grid1<int>grid1;
    grid1.setElementAt(3,3,78);
    cout << grid1.getElementAt(3,3) << endl;

    Grid<char*> strGrid(2,2);
    string d="dada";
    strGrid.setElementAt(0,0,d.c_str());
    strGrid.setElementAt(1,1,"salo");
    cout << strGrid.getElementAt(0,0) << endl;
    cout << strGrid.getElementAt(1,1) << endl;

    GridContainer<int,vector<int>> intGrid1;

    intGrid1.setElementAt(5,6,(3,4));
    intGrid1.setElementAt(7,8,9);
    cout<<intGrid1.getElementAt(5,6)<< endl;
    cout<<intGrid1.getElementAt(7,8)<< endl;

    return 0;
}
