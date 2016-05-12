//
// Created by abondar on 12.05.16.
//

#include "BuddyList.h"

void BuddyList::addBuddy(const string& name, const string& buddy){
    if (!isBuddy(name,buddy)){
        buddies.insert({name,buddy});
    }
}

void BuddyList::removeBuddy(const string& name, const string& buddy){
    auto strart = buddies.lower_bound(name);
    auto end = buddies.upper_bound(name);

    for (;strart!=end;++strart){
        if (strart->second == buddy){
            buddies.erase(strart);
            break;
        }
    }
}

bool BuddyList::isBuddy(const string& name, const string& buddy) const{
    auto strart = buddies.lower_bound(name);
    auto end = buddies.upper_bound(name);

    for (;strart!=end;++strart){
        if (strart->second == buddy){
            return true;
        }
    }
}

list<string> BuddyList::getBuddies(const string& name) const{
    //pair of iterators
    auto its = buddies.equal_range(name);

    list<string>buddies;
    for(; its.first!=its.second;++its.first){
        buddies.push_back(its.first->second);
    }

    return buddies;
}