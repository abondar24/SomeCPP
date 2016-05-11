//
// Created by abondar on 09.05.16.
//

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

auto main() -> int {
    vector<int> vector1(10, 0);
    vector<int> vector2(10, 0);

    if (vector1 == vector2) {
        cout << "equal!" << endl;
    } else {
        cout << "not equal!" << endl;
    }
    vector1[3] = 7;
    if (vector1 < vector2) {
        cout << "vector 1 is less than vector 2" << endl;
    } else {
        cout << "vector 1 is greater than vector 2" << endl;
    }

    for (vector<int>::iterator iter = vector2.begin(); iter != vector2.end(); ++iter) {

        cout << *iter << " ";
    }

    vector<string> vector3;
    for (auto &str: vector3) {
        str.append("A");
    }



    return 0;
}