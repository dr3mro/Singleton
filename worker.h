#ifndef WORKER_H
#define WORKER_H
#include <thread>
#include <queue>
#include <iostream>
#include <chrono>

extern std::mutex _mutex;
class Worker
{
public:
    static void Start(bool &stop, std::queue<char> &list, void(*callback)(std::string));

private:
};

#endif // WORKER_H
