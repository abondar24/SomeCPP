//
// Created by abondar on 12.05.16.
//

#include "BankDB.h"


bool BankDB::addAccount(const BankAccount &acc) {
    auto res = mAccounts.insert(make_pair(acc.getAccNum(), acc));
    return res.second;
}

void BankDB::deleteAccount(int accNum) {
    mAccounts.erase(accNum);
}

BankAccount& BankDB::findAccount(int accNum) throw(std::out_of_range){
    //find by key
    auto it = mAccounts.find(accNum);
    if (it == mAccounts.end()){
        throw out_of_range("No account with that number");
    }

    return it->second;
}

BankAccount& BankDB::findAccount(const std::string &name) throw(std::out_of_range){
    //find by non-key attr
    for (auto& p: mAccounts){
        if (p.second.getClientName() == name){
            //found
            return p.second;
        }
    }
    throw out_of_range("No account with that number");
}

void BankDB::mergeDataBase(BankDB &db){
    mAccounts.insert(db.mAccounts.begin(),db.mAccounts.end());
    db.mAccounts.clear();
}
