//
// Created by abondar on 12.06.16.
//
#include<atomic>
#include <iostream>
using namespace std;
int main(){
    atomic<int> value(10);
    cout<<"val = "<<value<<endl;
    int fetched = value.fetch_add(4);
    cout<<"val = "<<value<<endl;
    cout<<"fetched = "<<fetched<<endl;

    return 0;
}