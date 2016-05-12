//
// Created by abondar on 12.05.16.
//

#include <iostream>
#include "CableCompany.h"

using namespace std;

int main()  {

    CableCompany cc;
    auto basic_pkg = "11110000";
    auto premium_pkg = "1111111";
    auto sports_pkg = "00001101";

    cc.addPackage("basic", bitset<numChannels>(basic_pkg));
    cc.addPackage("premium", bitset<numChannels>(premium_pkg));
    cc.addPackage("sports", bitset<numChannels>(sports_pkg));

    cc.newCustomer("Vasya Pupkin","premium");
    cc.addPackageToCutomer("Vasya Pupkin", "sports");

    cout << cc.getCustomerChannels("Vasya Pupkin") << endl;

    return 0;
}