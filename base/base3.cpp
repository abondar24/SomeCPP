//
// Created by abondar on 09.05.16.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <bits/regex.h>


using namespace std;

function<int(void)> multBy2(int x);

function<int(void)> multBy3(int x);

void testCallBack(const vector<int> &vec, const function<bool(int)> &callback);

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


    unordered_map<int, string> um = {
            {1, "item 1"},
            {2, "item 2"},
            {3, "item 3"},
            {4, "item 4"}
    };

    for (auto &p:um) {
        cout << p.first << " = " << p.second << endl;
    }

    [] { cout << "Test lambda" << endl; }();

    string result = [](const string &str) { return "Hello from " + str; }("California");
    cout << "Result: " << result << endl;

    auto fn = [](const string &str) { return "Hello from " + str; };

    cout << fn("Massachusets") << endl;

    auto fn2 = multBy2(5);
    cout << fn2() << endl;

    auto fn3 = multBy3(7);
    cout << fn3() << endl;

    int k = 8;
    testCallBack(vector1, [=, &k](int i) { return i < k; });

    vector<int> vector4 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int index = 0;
    for_each(vector4.begin(), vector4.end(), [&index](int i) { cout << i * 4 << ":" << (index++) << endl; });


    //function object adapter
    //find first greater than 2
    //,placeholders::_1 - implementation defined maximum number.
    // When used as an argument in a std::bind expression, the placeholder objects are stored
    // in the generated function object, and when that function object is invoked with unbound arguments,
    // each placeholder _N is replaced by the corresponding Nth unbound argument.
    auto it = find_if(vector4.begin(), vector4.end(), bind(greater<int>(), placeholders::_1, 2));
    cout << *it << endl;

    //we also have mx,search,first_of,find_n - see the doc
    auto it1 = min_element(vector4.begin(), vector4.end());
    cout << *it1 << endl;

    //more readable than greater example
    auto it2 = find_if(vector4.begin(), vector4.end(), [](int i) { return i % 2 == 0; });
    cout << *it2 << endl;

    transform(vector4.begin(), vector4.end(), vector4.begin(), [](int i) { return i * 200; });
    for (auto &i: vector4) {
        cout << i << endl;

    }


    return 0;
}

//function wrapper
function<int(void)> multBy2(int x) {
    //capture by val
    return [=]() -> int { return 2 * x; };
}

function<int(void)> multBy3(int x) {
    //capture by ref
    return [&]() -> int { return 3 * x; };
}

void testCallBack(const vector<int> &vec, const function<bool(int)> &callback) {
    for (auto i:vec) {
        if (!callback(i))
            break;
        cout << i << " ";
    }
    cout << endl;
}