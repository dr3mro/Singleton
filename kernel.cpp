#include "kernel.h"

Kernel* Kernel::instance = nullptr;

Kernel* Kernel::getInstance(std::thread &t, bool &stop, std::vector<char> &list)
{
    if (instance == nullptr)
    {
        instance = new Kernel(t,stop,list);
    }

    return instance;
}

void Kernel::callback(std::string s)
{
    std::cout << s << std::endl;
}

Kernel::Kernel(std::thread &t, bool &stop, std::vector<char> &list)
{
    t = std::thread(&Worker::Start,std::ref(stop),std::ref(list),std::ref(*callback));
}

Kernel::~Kernel()
{
    delete instance;
}
