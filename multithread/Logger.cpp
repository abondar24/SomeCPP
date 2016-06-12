//
// Created by abondar on 12.06.16.
//


#include <iostream>
#include "Logger.h"
using namespace std;

Logger::Logger(): mThreadStarted(false),mExit(false){
    mThread = thread(&Logger::processEntries,this);
    //wait until back thread starts processing
    unique_lock<mutex> lock(mMutexStarted);
    mCondVarStarted.wait(lock,[&](){ return mThreadStarted == true;});
}

Logger::~Logger() {
    //shut down the thread gracefully
    mExit = true;
    mCondVar.notify_all();
    mThread.join();
}

void Logger::log(const std::string& entry){
   unique_lock<mutex> lock(mMutex);
    mQueue.push(entry);
    mCondVar.notify_all();
}

void Logger::processEntries(){

    unique_lock<mutex> lock(mMutex);
    mThreadStarted = true;
    mCondVarStarted.notify_all();
    while (true){
        mCondVar.wait(lock);
        lock.unlock();
        while (true){
            lock.lock();
            if (mQueue.empty()){
                break;
            } else {
                cout << mQueue.front() << endl;
                mQueue.pop();
            }
            lock.unlock();
        }
        if (mExit){
            break;
        }
    }
}
