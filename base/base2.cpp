//
// Created by abondar on 06.05.16.
//


#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/unique_ptr.h>
#include "FileOpenError.h"
#include "FileReadError.h"
#include "MyArray.h"

using namespace std;

void separateOddsEvens(const int arr[], int size, int** odds,
                       int* numOdds, int** evens, int* numEvens);

void separateOddsEvens1(const int arr[], int size, int*& odds,
                        int& numOdds, int*& evens, int& numEvens);

void separateOddsEvens2(const vector<int>& arr, vector<int>& odds, vector<int>& evens);


void readIntFile(const string& fileName, vector<int>& dest) throw(FileOpenError, FileReadError);

typedef vector<string> StringVector;

auto main() -> int {

    int x = 3;
    cout << x << endl;

    int& rx = x;
    int y = 5;

    rx = y;
    cout << x << endl;

    int* ptr = &rx;
    cout << ptr << endl;

    int unsplit[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *oddNums,*evenNums;
    int numOdds, numEvens;

    vector<int> unsplitVec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> odds, evens;

    separateOddsEvens(unsplit, 10, &oddNums, &numOdds, &evenNums, &numEvens);

    try {
        separateOddsEvens1(unsplit, 10, oddNums, numOdds, evenNums, numEvens);
    } catch (int a) {
        return 7;
    }

    try {
        separateOddsEvens2(unsplitVec, odds, evens);
    } catch (...) {
        cerr << "Vector error" << endl;
    }

    StringVector stV;
    stV.push_back("1");
    x = (int) stV.size();
    cout << x << endl;



    try{
      ptr = new int[3];
    } catch (const bad_alloc& e){
        cerr << __FILE__ << "(" << __LINE__
        << "): Unable to allocate memory!" << endl;
        return 2;
    }
    delete ptr;



    MyArray<int> arrInt(7);
    cout << "Array size: " << arrInt.getSize() << endl;
    arrInt.at(3)=7;
    cout << "Array at 3: " << arrInt.at(3) << endl;
    try{
        arrInt.at(10)=3;
    } catch (const exception& e){
        cout <<"Caught exception: '" <<e.what() <<"'"<<endl;
    }

    MyArray<string> arrStr(3);
    cout << "Array size: " << arrStr.getSize() << endl;
    arrStr.at(1)="This a story of the ... ";
    cout << "Array at 1: " << arrStr.at(1) << endl;

    string fileName = "/home/abondar/agents.csv";
    vector<int> intVec;

    try{
        readIntFile(fileName,intVec);
    } catch (const FileError& e){
        cerr << e.what() << endl;
        return 1;
    }



    return 0;
}

void separateOddsEvens(const int arr[], int size, int** odds,
                       int* numOdds, int** evens, int* numEvens) {

    //determine sizes of arrays
    *numOdds = *numEvens = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 1) {
            (*numOdds)++;
        } else {
            (*numEvens)++;
        }
    }

    //allocate memory for new arrays
    *odds = new int[*numOdds];
    *evens = new int[*numEvens];
    int oddsPos = 0, evensPos = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 1) {
            (*odds)[oddsPos++] = arr[i];
        } else {
            (*evens)[evensPos++] = arr[i];
        }
    }
}

void separateOddsEvens1(const int arr[], int size, int*& odds,
                        int& numOdds, int*& evens, int& numEvens) {

    //determine sizes of arrays
    numOdds = numEvens = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 1) {
            numOdds++;
        } else {
            numEvens++;
        }
    }

    //allocate memory for new arrays
    odds = new int[numOdds];
    evens = new int[numEvens];
    int oddsPos = 0, evensPos = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 1) {
            odds[oddsPos++] = arr[i];
        } else {
            evens[evensPos++] = arr[i];
        }
    }
}

void separateOddsEvens2(const vector<int>& arr, vector<int>& odds, vector<int>& evens) {
    for (auto& i :arr) {
        if (i % 2 == 1) {
            odds.push_back(i);
        } else {
            evens.push_back(i);
        }
    }

}

void readIntFile(const string& fileName, vector<int>& dest) throw(FileOpenError, FileReadError) {

    ifstream istr;
    int temp;
    string line;
    int lineNumber = 0;
    istr.open(fileName.c_str());
    if (!istr.fail()) {
        throw FileOpenError(fileName);
    }

    while (!istr.eof()) {
        //read line by line
        getline(istr, line);
        lineNumber++;

        //create  a string stream out of the line.
        istringstream lineStream(line);

        //read integers
        while (lineStream >> temp) {
            dest.push_back(temp);
        }
        if (!lineStream.eof()) {
            istr.close();
            throw FileReadError(fileName, lineNumber);
        }
    }

    istr.close();

}