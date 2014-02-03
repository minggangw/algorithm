// NumberOf1InBinary.cpp : Defines the entry point for the console application.
//

// ¡¶œ£ÖžOffer¡ª¡ªÃûÆóÃæÊÔ¹ÙŸ«œ²µäÐÍ±à³ÌÌâ¡·ŽúÂë
// Öø×÷ÈšËùÓÐÕß£ººÎº£ÌÎ

#include <cstdio>
#include <cstdlib>

int NumberOf1_Solution1(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if(n & flag)
            count ++;

        flag = flag << 1;
    }

    return count;
}

int NumberOf1_Solution2(int n)
{
    int count = 0;

    while (n)
    {
        ++ count;
        n = (n - 1) & n;
    }

    return count;
}

void Test(int number, unsigned int expected)
{
    int actual = NumberOf1_Solution1(number);
    if(actual == expected)
        printf("Solution1: Test for %p passed.\n", number);
    else
        printf("Solution1: Test for %p failed.\n", number);

    actual = NumberOf1_Solution2(number);
    if(actual == expected)
        printf("Solution2: Test for %p passed.\n", number);
    else
        printf("Solution2: Test for %p failed.\n", number);

    printf("\n");
}

int main(int argc, char* argv[])
{
    // ÊäÈë0£¬ÆÚŽýµÄÊä³öÊÇ0
    Test(0, 0);

    // ÊäÈë1£¬ÆÚŽýµÄÊä³öÊÇ1
    Test(1, 1);

    // ÊäÈë10£¬ÆÚŽýµÄÊä³öÊÇ2
    Test(10, 2);

    // ÊäÈë0x7FFFFFFF£¬ÆÚŽýµÄÊä³öÊÇ31
    Test(0x7FFFFFFF, 31);

    // ÊäÈë0xFFFFFFFF£šžºÊý£©£¬ÆÚŽýµÄÊä³öÊÇ32
    Test(0xFFFFFFFF, 32);

    // ÊäÈë0x80000000£šžºÊý£©£¬ÆÚŽýµÄÊä³öÊÇ1
    Test(0x80000000, 1);

    unsigned int i = 0x80000000;

    printf("i = %d\n", i);
    return 0;
}

