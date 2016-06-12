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
            //timed lock
            unique_lock<timed_mutex>lock(mTimedMutex,chrono::milliseconds(200));
            if (lock){
                cout<<"Counter "<< mId<<" val ";
                cout << i<<endl;
            } else {
                //lock is not acquired
            }

        }
    }


protected:
    int mId;
    int mNumIters;
    static timed_mutex mTimedMutex;
};

timed_mutex Counter::mTimedMutex;

int main(){
    cout.sync_with_stdio(true); //sure cout is thread safe
    thread t1(Counter(1,10));
    thread t2(Counter(2,20));

    t1.join();
    t2.join();
    return 0;
}
