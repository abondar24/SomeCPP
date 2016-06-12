//
// Created by abondar on 12.06.16.
//

#include <mutex>

using namespace std;

mutex m1;
mutex m2;

void process()
{
    unique_lock<mutex> lock1(m1, defer_lock_t());
    unique_lock<mutex> lock2(m2, defer_lock_t());
    lock(lock1, lock2);
    // Locks acquired
}

int main()
{
    process();

    return 0;
}