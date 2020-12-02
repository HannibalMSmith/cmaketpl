#include "foo.h"
#include <iostream>
#include "config.h"
void foo::run()
{
    std::cout << TEST <<" foo::run with speed:" << data_ << "km/h" << std::endl;

}