#include "worker.h"

using namespace std::chrono_literals;


void Worker::Start(bool& stop, std::queue<char> &list,void(*callback)(std::string))
{
    while (!stop)
    {
        std::this_thread::sleep_for(500ms);
        while (!list.empty())
        {
            std::this_thread::sleep_for(500ms);
            std::string message = std::to_string(list.size()) + " :: " + list.front();
            (*callback)(message);
            _mutex.lock();
            list.pop();
            _mutex.unlock();
            if(stop) break;
            if(list.size()==0)
                (*callback)(std::string("No more Items\n"));
        }
    }
    (*callback)(std::string("Exiting ..."));
}
