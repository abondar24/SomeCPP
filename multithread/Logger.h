//
// Created by abondar on 12.06.16.
//

#ifndef SOMECPP_LOGGER_H
#define SOMECPP_LOGGER_H


#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>

class Logger {
public:
    Logger();
    virtual ~Logger();
    //add log entry to queue
    void log(const std::string& entry);

protected:
    void processEntries();
    bool mThreadStarted;
    std::mutex mMutex;
    std::condition_variable mCondVar;
    std::queue<std::string> mQueue;
    std::thread mThread;
    std::mutex mMutexStarted;
    std::condition_variable mCondVarStarted;

private:
    Logger(const Logger& src);
    Logger& operator=(const Logger& rhs);
    bool mExit;
};


#endif //SOMECPP_LOGGER_H
