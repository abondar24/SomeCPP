//
// Created by abondar on 12.05.16.
//

#ifndef SOMECPP_BANKDB_H
#define SOMECPP_BANKDB_H


#include <map>
#include "BankAccount.h"

class BankDB {
public:
    BankDB(){}
    bool addAccount(const BankAccount& acc);
    void deleteAccount(int accNum);
    BankAccount& findAccount(int accNum) throw(std::out_of_range);
    BankAccount& findAccount(const std::string& name) throw(std::out_of_range);
    void mergeDataBase(BankDB& db);

protected:
    std::map<int,BankAccount>mAccounts;
};


#endif //SOMECPP_BANKDB_H
