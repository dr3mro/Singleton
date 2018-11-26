#include <iostream>
#include "kernel.h"
#include <thread>
#include <queue>
#include <chrono>


using namespace std;
using namespace std::chrono_literals;
static Kernel* K;
std::mutex _mutex;

int main()
{
    bool stop=false;

    std::thread t;

    std::queue<char> list;



    K = Kernel::getInstance(t,stop,list);

    char x;
    while(!stop)
    {
        std::cin >> x;
        stop = !(std::strcmp("0",&x));
        _mutex.lock();
        list.emplace(x);
        _mutex.unlock();
    }

    if(t.joinable())
        t.join();

    return 0;
}
