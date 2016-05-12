//
// Created by abondar on 12.05.16.
//

#ifndef SOMECPP_ACL_H
#define SOMECPP_ACL_H

#include <set>
#include <string>
#include <list>

using std::set;
using std::string;
using std::list;
using std::initializer_list;

class ACL {
public:

    ACL() { };

    ACL(const initializer_list<string>& initList);

    void addUser(const string& user);

    void removeUser(const string& user);

    bool isAllowed(const string& user);

    list<string> getAllUsers() const;

protected:
    set<string>allowed;


};


#endif //SOMECPP_ACL_H
