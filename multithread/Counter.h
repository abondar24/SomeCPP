//
// Created by abondar on 12.06.16.
//

#ifndef SOMECPP_COUNTER_H
#define SOMECPP_COUNTER_H

#include <iostream>
using namespace std;
class Counter{
public:
    Counter(int id,int numIters):mId(id),mNumIters(numIters){}

    void operator()() const{

        for(int i=0; i<mNumIters;++i){
            cout<<"Counter "<< mId<<" val ";
            cout << i<<endl;
        }
    }


protected:
    int mId;
    int mNumIters;
};
#endif //SOMECPP_COUNTER_H
