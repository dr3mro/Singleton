#ifndef KERNEL_H
#define KERNEL_H

#include <iostream>
#include <thread>
#include <queue>
#include "worker.h"
#include <mutex>

class Kernel
{
private:
    Kernel(std::thread &t, bool &stop, std::queue<char> &list);
    ~Kernel()=default;

    Kernel(const Kernel&) = delete;
    Kernel& operator=(const Kernel&) = delete;
    Kernel(Kernel&&) = delete;
    Kernel& operator=(Kernel&&) = delete;

public:
    static Kernel* getInstance(std::thread &t, bool &stop, std::queue<char> &list);
    static void callback(std::string s);
    std::mutex _mutex;


};
#endif // KERNEL_H
