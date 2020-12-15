#idndef LEARNCMAKE_FOO
#define LEARNCMAKE_FOO
#include "config.h"

class foo
{
private:
    int data_;
public:
    foo(int data) : data_(data){}
    foo(const foo &rhs) = delete;
    foo& operator=(const foo &rhs) = delete;
    ~foo() = default;
    void run();
};

#endif
