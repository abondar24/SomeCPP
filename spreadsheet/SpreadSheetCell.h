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

    SpreadSheetCell(const SpreadSheetCell &src);

    //copy constructor
    SpreadSheetCell(const string &initVal);

    void set(double inVal);

    void set(const string &inStr);

    //inline funcs
    double getValue() const {
        numAccesses++;
        return val;
    }

    string getString() const {
        numAccesses++;
        return str;
    }

    typedef enum {
        Red = 1, Green = 2, Blue = 3, Yellow = 4
    } Colors;

    void setColor(Colors color);

    bool checkSpreadSheetCell(const SpreadSheetCell &cell);

    //global operator
    friend const SpreadSheetCell operator+(const SpreadSheetCell& lc, const SpreadSheetCell& rc);

    friend const SpreadSheetCell operator*(const SpreadSheetCell& lc, const SpreadSheetCell& rc);

    friend const SpreadSheetCell operator-(const SpreadSheetCell& lc, const SpreadSheetCell& rc);

    friend const SpreadSheetCell operator/(const SpreadSheetCell& lc, const SpreadSheetCell& rc);

    friend bool operator==(const SpreadSheetCell& lc, const SpreadSheetCell& rc);
    friend bool operator>(const SpreadSheetCell& lc, const SpreadSheetCell& rc);
    friend bool operator<(const SpreadSheetCell& lc, const SpreadSheetCell& rc);
    friend bool operator!=(const SpreadSheetCell& lc, const SpreadSheetCell& rc);
    friend bool operator>=(const SpreadSheetCell& lc, const SpreadSheetCell& rc);
    friend bool operator<=(const SpreadSheetCell& lc, const SpreadSheetCell& rc);

    SpreadSheetCell& operator+=(const SpreadSheetCell& rc);

    SpreadSheetCell& operator-=(const SpreadSheetCell& rc);

    SpreadSheetCell& operator*=(const SpreadSheetCell& rc);

    SpreadSheetCell& operator/=(const SpreadSheetCell& rc);

protected:
//    string doubleToString(double inVal) const;
//    double stringToDouble(string& inString) const;

    static string doubleToString(double inVal);

    static double stringToDouble(string &inString);

    double val;
    string str;
    mutable int numAccesses;

    //mutable int numAccesses=0; //C++11

    Colors mColor = Red;
};


#endif //SOMECPP_SPREADSHEETCELL_H
