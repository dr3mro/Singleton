#include <iostream>
#include "kernel.h"
#include <thread>
#include <vector>
#include <chrono>


using namespace std;
using namespace std::chrono_literals;
static Kernel* K;


int main()
{
    bool stop=false;

    std::thread t;

    std::vector<char> list;

    K = Kernel::getInstance(t,stop,list);

    char x;
    while(!stop)
    {
        std::cin >> x;
        stop = !(std::strcmp("0",&x));
        list.emplace_back(x);
        std::this_thread::sleep_for(100ms);
    }

    if(t.joinable())
        t.join();

    return 0;
}
