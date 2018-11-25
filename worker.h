#ifndef WORKER_H
#define WORKER_H
#include <thread>
#include <queue>
#include <iostream>
#include <chrono>

class Worker
{
public:
    static void Start(bool &stop, std::queue<char> &list, void(*callback)(std::string), std::mutex &_mutex);

private:
};

#endif // WORKER_H
