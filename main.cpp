#include <iostream>
#include "TestConfig.h"
#include "foo.h"
#include "utils/fooutils.h"

int main(int argc, char **argv)
{
    if (argc < 2) 
    {

        std::cout << argv[0] << " Version " << Test_VERSION_MAJOR << "."
        << Test_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
    }
    foo bar(100);
    bar.run();

    ext_run(5).join();

    return 0;
}