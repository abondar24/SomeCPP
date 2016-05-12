//
// Created by abondar on 12.05.16.
//

#include "ACL.h"

ACL::ACL(const initializer_list<string>& initList){
    for(auto& user:initList){
        addUser(user);
    }
}

void ACL::addUser(const string& user){
    allowed.insert(user);
}

void ACL::removeUser(const string& user){
    allowed.erase(user);
}

bool ACL::isAllowed(const string& user){
    return (allowed.count(user)==1);
}

list<string> ACL::getAllUsers() const{
    list<string> users;
    users.insert(users.end(),allowed.begin(),allowed.end());
    return users;
}