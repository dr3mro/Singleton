#include "kernel.h"

Kernel* Kernel::getInstance(std::thread &t, bool &stop, std::queue<char> &list)
{

    static Kernel *instance = new Kernel(t,stop,list);
    return instance;
}

void Kernel::callback(std::string s)
{
    std::cout << s << std::endl;
}

Kernel::Kernel(std::thread &t, bool &stop, std::queue<char> &list)
{
    t = std::thread(&Worker::Start,std::ref(stop),std::ref(list),std::ref(callback));
}
