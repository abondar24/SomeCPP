//
// Created by abondar on 12.05.16.
//

#include "BuddyList.h"

#include <iostream>
using namespace std;

auto main() ->int{

    BuddyList buddies;
    buddies.addBuddy("Vasya Pupkin","Volan De Mort");
    buddies.addBuddy("Vasya Pupkin","Rudolf Steiner");
    buddies.addBuddy("Vasya Pupkin","VVS");
    buddies.addBuddy("Vasya Pupkin","Anton Spak");
    buddies.addBuddy("Vasya Pupkin","Petya Ivanov");

    buddies.removeBuddy("Vasya Pupkin","VVS");

    buddies.addBuddy("Petya Ivanov","Vasya Pupkin");
    buddies.addBuddy("Petya Ivanov","Volan De Mort");

    auto buds =  buddies.getBuddies("Vasya Pupkin");
    for (auto& name:buds){
        cout<<"\t"<<name<<endl;
    }


    return 0;
}