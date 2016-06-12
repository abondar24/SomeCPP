//
// Created by abondar on 12.06.16.
//
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

class Counter{
public:
    Counter(int id,int numIters):mId(id),mNumIters(numIters){}

    void operator()() const{

        for(int i=0; i<mNumIters;++i){
            //thread safe lock
            lock_guard<mutex> lock(mMutex);
            cout<<"Counter "<< mId<<" val ";
            cout << i<<endl;
        }
    }


protected:
    int mId;
    int mNumIters;
    static mutex mMutex;
};

mutex Counter::mMutex;

int main(){
    cout.sync_with_stdio(true); //sure cout is thread safe
    thread t1(Counter(1,10));
    thread t2(Counter(2,20));

    t1.join();
    t2.join();
    return 0;
}