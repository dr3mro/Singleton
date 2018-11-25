#include <iostream>
#include "kernel.h"
#include <thread>
#include <queue>
#include <chrono>


using namespace std;
using namespace std::chrono_literals;
static Kernel* K;


int main()
{
    bool stop=false;

    std::thread t;

    std::queue<char> list;

    K = Kernel::getInstance(t,stop,list);

    std::mutex *_mutex = &(K->_mutex);
    char x;
    while(!stop)
    {
        std::cin >> x;
        stop = !(std::strcmp("0",&x));
        _mutex->lock();
        list.emplace(x);
        _mutex->unlock();
        //std::this_thread::sleep_for(100ms);
    }

    if(t.joinable())
        t.join();

    return 0;
}
