//
// Created by abondar on 12.06.16.
//


#include <iostream>
#include <thread>

using namespace std;

class Request{
public:
    Request(int id):mId(id){}
    void process(){
        cout << "Request processing "<<mId << endl;
    }

protected:
    int mId;
};

void counter(int id,int numIters){

    for(int i=0; i<numIters;++i){
        cout<<"Counter "<< id<<" val ";
        cout << i<<endl;
    }
}

int main(){
cout.sync_with_stdio(true); //sure cout is thread safe
    thread t1(counter,1,6);
    thread t2(counter,2,4);

    //lambda thread
    thread t3([](int id,int numIters){
        for(int i=0; i<numIters;++i){
            cout<<"Counter "<< id<<" val ";
            cout << i<<endl;
        }
    },3,7);

    Request req(100);
    thread t4(&Request::process, &req);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}