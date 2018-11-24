#include "worker.h"

using namespace std::chrono_literals;


void Worker::Start(bool& stop, std::vector<char> &list,void(*callback)(std::string),std::mutex& _mutex)
{
    while (!stop)
    {
        std::this_thread::sleep_for(1s);
        while (list.size()>0)
        {
            std::this_thread::sleep_for(1s);
            std::string message = std::to_string(list.size()) + " :: " + list.back();
            callback(message);
            _mutex.lock();
            list.pop_back();
            _mutex.unlock();
            if(stop) break;
            if(list.size()==0)
                callback(std::string("No more Items\n"));
        }
    }
    callback(std::string("Exiting ..."));
}
