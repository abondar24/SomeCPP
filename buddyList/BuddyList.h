//
// Created by abondar on 12.05.16.
//

#ifndef SOMECPP_BUDDYLIST_H
#define SOMECPP_BUDDYLIST_H


#include <string>
#include <list>
#include <map>

using std::multimap;
using std::string;
using std::list;

class BuddyList {
public:
    BuddyList(){};

    void addBuddy(const string& name, const string& buddy);

    void removeBuddy(const string& name, const string& buddy);

    bool isBuddy(const string& name, const string& buddy) const;

    list<string> getBuddies(const string& name) const;

protected:
    multimap<string,string> buddies;
};


#endif //SOMECPP_BUDDYLIST_H
