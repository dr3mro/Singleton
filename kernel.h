#ifndef KERNEL_H
#define KERNEL_H

#include <iostream>
#include <thread>
#include <vector>
#include "worker.h"

class Kernel
{
private:
    static Kernel* instance;
    Kernel(std::thread &t, bool &stop, std::vector<char> &list);
    ~Kernel();

public:
    static Kernel* getInstance(std::thread &t, bool &stop, std::vector<char> &list);
    static void callback(std::string s);


};
#endif // KERNEL_H
