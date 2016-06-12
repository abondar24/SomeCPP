#include <iostream>

//
// Created by abondar on 12.06.16.
//

#include <mutex>
#include <thread>
using namespace std;

//call once helps us to be sure that function executes once
class Data{
public:
    void operator()(){
        call_once(mOnceFlag,&Data::init,this);
        cout << "Work" <<endl;
    }

protected:
    void init(){
        cout << "init()"<<endl;
        mMemory = new char(24);
    }
    mutable once_flag mOnceFlag;
    mutable char* mMemory;
};

int main(){
    cout.sync_with_stdio(true);
    Data d;

    thread t1{ref(d)};
    thread t2{ref(d)};
    thread t3{ref(d)};

    t1.join();
    t2.join();
    t3.join();

    return 0;
}