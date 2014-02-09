#include <cstdio>
#include <cstddef>
#include <cstdlib>

#include "AutoPtr.h"

class TestAutoPtr
{
    public:
        TestAutoPtr() { printf("class is constructing\n"); }
        ~TestAutoPtr() { printf("class is deconstructing\n"); }
};

void Test()
{
    TestAutoPtr* p = new TestAutoPtr();
    AutoPtr<TestAutoPtr> ap(p);
}

int main()
{
    Test();
    return 0;
}
