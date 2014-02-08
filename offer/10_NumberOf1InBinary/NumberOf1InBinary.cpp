// NumberOf1InBinary.cpp : Defines the entry point for the console application.
//

// ¡¶œ£ÖžOffer¡ª¡ªÃûÆóÃæÊÔ¹ÙŸ«œ²µäÐÍ±à³ÌÌâ¡·ŽúÂë
// Öø×÷ÈšËùÓÐÕß£ººÎº£ÌÎ

#include <cstdio>
#include <cstdlib>

typedef unsigned int uint32;  //assume this gives 64-bits
const uint32 m1  = 0x55555555; //binary: 0101...
const uint32 m2  = 0x33333333; //binary: 00110011..
const uint32 m4  = 0x0f0f0f0f; //binary:  4 zeros,  4 ones ...
const uint32 m8  = 0x00ff00ff; //binary:  8 zeros,  8 ones ...
const uint32 m16 = 0x0000ffff; //binary: 16 zeros, 16 ones ...
// const uint32 m32 = 0x00000000ffffffff; //binary: 32 zeros, 32 ones ...
// const uint32 hff = 0xffffffffffffffff; //binary: all ones
// const uint32 h01 = 0x0101010101010101; //the sum of 256 to the power of 0,1,2,3...
 
//This is a naive implementation, shown for comparison,
//and to help in understanding the better functions.
//It uses 24 arithmetic operations (shift, add, and).
int NumberOf1_Solution3(int  x) {
    x = (x & m1 ) + ((x >>  1) & m1 ); //put count of each  2 bits into those  2 bits 
    x = (x & m2 ) + ((x >>  2) & m2 ); //put count of each  4 bits into those  4 bits 
    x = (x & m4 ) + ((x >>  4) & m4 ); //put count of each  8 bits into those  8 bits 
    x = (x & m8 ) + ((x >>  8) & m8 ); //put count of each 16 bits into those 16 bits 
    x = (x & m16) + ((x >> 16) & m16); //put count of each 32 bits into those 32 bits 
    // x = (x & m32) + ((x >> 32) & m32); //put count of each 64 bits into those 64 bits 
    return x;
}

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

    actual = NumberOf1_Solution3(number);
    if(actual == expected)
        printf("Solution3: Test for %p passed.\n", number);
    else
        printf("Solution3: Test for %p failed.\n", number);

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

