//
// Created by abondar on 12.05.16.
//

#include "ACL.h"
#include <iostream>
using namespace std;

auto main() -> int {

    ACL fileX = {"nsolter","klep","baduser"};
    fileX.removeUser("baduser");
    if(fileX.isAllowed("nsolter")){
        cout << "nsolter has permissions"<<endl;
    }
    if(fileX.isAllowed("baduser")){
        cout << "baduser has permissions"<<endl;
    }

    auto users = fileX.getAllUsers();
    for (auto& user:users){
        cout<< user << " ";
    }

    return 0;
}