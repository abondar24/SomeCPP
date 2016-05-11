//
// Created by abondar on 12.05.16.
//

#ifndef SOMECPP_BANKACCOUNT_H
#define SOMECPP_BANKACCOUNT_H

#include <iostream>

using namespace std;
class BankAccount{
public:
    BankAccount(int accNum, const std::string& name): mAccNum(accNum), mClientName(name){}
    void setAccNum(int accNum){mAccNum = accNum;}
    int getAccNum()const { return mAccNum;}
    void setClientName(const std::string& name){ mClientName = name;}
    std::string getClientName() const { return mClientName;}

protected:
    int mAccNum;
    std::string mClientName;
};
#endif //SOMECPP_BANKACCOUNT_H
