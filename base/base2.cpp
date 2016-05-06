//
// Created by abondar on 06.05.16.
//


#include <vector>
#include <string>
#include <iostream>

using namespace std;

void separateOddsEvens(const int arr[], int size, int **odds,
                       int *numOdds, int **evens, int *numEvens);

void separateOddsEvens1(const int arr[], int size, int *&odds,
                        int &numOdds, int *&evens, int &numEvens);

void separateOddsEvens2(const vector<int> &arr, vector<int> &odds, vector<int> &evens);

typedef vector<string> StringVector;

auto main() -> int {

    int x = 3;
    cout << x << endl;

    int &rx = x;

    int y = 5;

    rx = y;
    cout << x << endl;

    int *ptr = &rx;
    cout << ptr << endl;

    int unsplit[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *oddNums, *evenNums;
    int numOdds, numEvens;

    vector<int> unsplitVec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> odds,evens;
    separateOddsEvens(unsplit, 10, &oddNums, &numOdds, &evenNums, &numEvens);
    separateOddsEvens1(unsplit, 10, oddNums, numOdds, evenNums, numEvens);
    separateOddsEvens2(unsplitVec,odds,evens);

    StringVector stV;
    stV.push_back("1");
    x = (int)stV.size();
    cout << x << endl;

    return 0;
}

void separateOddsEvens(const int arr[], int size, int **odds,
                       int *numOdds, int **evens, int *numEvens) {

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
    int oddsPos = 0, evensPos = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 1) {
            (*odds)[oddsPos++] = arr[i];
        } else {
            (*evens)[evensPos++] = arr[i];
        }
    }
}

void separateOddsEvens1(const int arr[], int size, int *&odds,
                        int &numOdds, int *&evens, int &numEvens) {

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

void separateOddsEvens2(const vector<int> &arr, vector<int> &odds, vector<int> &evens) {
    for (auto &i :arr) {
        if (i % 2 == 1){
            odds.push_back(i);
        } else{
            evens.push_back(i);
        }
    }

}