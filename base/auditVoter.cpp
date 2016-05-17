//
// Created by abondar on 18.05.16.
//
#include <iostream>
#include <set>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

typedef map<string, std::list<string>> VotersMap;
typedef pair<const string, std::list<string>> DistrictPair;

set<string> getDuplicates(VotersMap &votersByDistrict);

void auditVoterRolls(VotersMap &votersByDistrict, const list <string> &convictedFelons);

auto main() -> int {

    VotersMap voters={
            {"Moscow",{"Vasya Pupkin","Petya Ivanov","Anton Spak"}},
            {"Kamyzak",{"Rusik","Azamat","Vera Stepanovna"}},
            {"SPB",{"Sergey Shnurov","Shnur Sergeev","Boris Salov"}}
    };

    list<string> felons = {"Rusik","Boris Salov"};

    auto printDistrict = [](const DistrictPair& district){
        cout << district.first << ":";
        for (auto& str :district.second){
            cout << " {"<<str << ")";
        }
        cout << endl;
    };

    cout << "Before audit:" <<endl;
    for_each(voters.cbegin(),voters.cend(),printDistrict);
    cout << endl;

    auditVoterRolls(voters,felons);

    cout << "After audit:" <<endl;
    for_each(voters.cbegin(),voters.cend(),printDistrict);
    cout << endl;

    return 0;
}


void auditVoterRolls(VotersMap &votersByDistrict, const list <string> &convictedFelons) {
    set<string> toRemove = getDuplicates(votersByDistrict);

    toRemove.insert(convictedFelons.cbegin(), convictedFelons.cend());
    for_each(votersByDistrict.begin(), votersByDistrict.end(), [&toRemove](DistrictPair &district) {
        auto it = remove_if(district.second.begin(), district.second.end(),
                            [&](const string &name) { return (toRemove.count(name) > 0); });
        district.second.erase(it, district.second.end());

    });
}

set<string> getDuplicates(VotersMap &votersByDistrict) {
    set<string> allNames;
    set<string> duplicates;

    for (auto &district :votersByDistrict) {
        for (auto &name:district.second) {
            if (!allNames.insert(name).second) {
                duplicates.insert(name);
            }
        }
    }


    return duplicates;
}