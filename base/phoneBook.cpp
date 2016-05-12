//
// Created by abondar on 12.05.16.
//

#include <iostream>
#include <unordered_map>

using namespace std;

template<class T>
void printMap(const T &m) {
    for (auto &p:m) {
        cout << p.first << " (Phone : " << p.second << ")" << endl;
    }
    cout << "-------" << endl;

}

auto main() -> int {
    unordered_map<string, string> um;
    um.insert({
                      {"Alex F.",  "343-6546565"},
                      {"Eddie D.", "123-3336785"},
                      {"Marc W.",  "343-7845565"},

              });

    printMap(um);

    um.insert(make_pair("John D.","321-987654"));
    um["Marco S"]="964-258147";
    um["Freddy K"]="999-666111";
    um.erase("Freddy K.");
    printMap(um);

    int bucket = um.bucket("Eddie D.");
    cout << "Eddie D. is in bucket "<< bucket << " which contains "
    << um.bucket_size(bucket)<<" elements:" << endl;


    cout << "There are " << um.bucket_count() << " buckets." << endl;
    cout << "Average number of elements in a bucket is " << um.load_factor() << endl;

    return 0;
}