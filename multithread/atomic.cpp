//
// Created by abondar on 12.06.16.
//

#include <vector>
#include <thread>
#include <iostream>
#include <atomic>


//on linux race condition sometimes occurs
void func(std::atomic<int>& counter){
    for(int i=0; i<10000;++i){
        ++counter;
    }
}


int main(){
    std::atomic<int> counter(0);
        std::vector<std::thread>threads;
        for(int i=0;i<10;++i){
            threads.push_back(std::thread{func,std::ref(counter)});
        }
        for(auto& t: threads){
            t.join();
            std::cout<<"Result = "<<counter<<std::endl;
        }


        return 0;
};