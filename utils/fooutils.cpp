#include "fooutils.h"
#include <iostream>
#include <unistd.h>
void run(int count, int interval)
{
    for (auto i = 0; i < count; i++)
    {
        std::cout << "ext_run from thread!" <<std::endl;
        usleep(interval*100);
    }
    
}

std::thread ext_run(int count, int interval)
{
    return std::thread(run, count, interval);
}