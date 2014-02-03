// SquenceOfBST.cpp : Defines the entry point for the console application.
//

// ¡¶œ£ÖžOffer¡ª¡ªÃûÆóÃæÊÔ¹ÙŸ«œ²µäÐÍ±à³ÌÌâ¡·ŽúÂë
// Öø×÷ÈšËùÓÐÕß£ººÎº£ÌÎ

#include <stdlib.h>
#include <stdio.h>

// BST£ºBinary Search Tree£¬¶þ²æËÑË÷Ê÷
bool VerifySquenceOfBST(int sequence[], int length)
{
    if(sequence == NULL || length <= 0)
        return false;

    int root = sequence[length - 1];

    // ÔÚ¶þ²æËÑË÷Ê÷ÖÐ×ó×ÓÊ÷µÄœáµãÐ¡ÓÚžùœáµã
    int i = 0;
    for(; i < length - 1; ++ i)
    {
        if(sequence[i] > root)
            break;
    }

    // ÔÚ¶þ²æËÑË÷Ê÷ÖÐÓÒ×ÓÊ÷µÄœáµãŽóÓÚžùœáµã
    int j = i;
    for(; j < length - 1; ++ j)
    {
        if(sequence[j] < root)
            return false;
    }

    // ÅÐ¶Ï×ó×ÓÊ÷ÊÇ²»ÊÇ¶þ²æËÑË÷Ê÷
    bool left = true;
    if(i > 0)
        left = VerifySquenceOfBST(sequence, i);

    // ÅÐ¶ÏÓÒ×ÓÊ÷ÊÇ²»ÊÇ¶þ²æËÑË÷Ê÷
    bool right = true;
    if(i < length - 1)
        right = VerifySquenceOfBST(sequence + i, length - i - 1);

    return (left && right);
}

// ====================²âÊÔŽúÂë====================
void Test(char* testName, int sequence[], int length, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(VerifySquenceOfBST(sequence, length) == expected)
        printf("passed.\n");
    else
        printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    int data[] = {4, 8, 6, 12, 16, 14, 10};
    Test("Test1", data, sizeof(data)/sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2()
{
    int data[] = {4, 6, 7, 5};
    Test("Test2", data, sizeof(data)/sizeof(int), true);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test3()
{
    int data[] = {1, 2, 3, 4, 5};
    Test("Test3", data, sizeof(data)/sizeof(int), true);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test4()
{
    int data[] = {5, 4, 3, 2, 1};
    Test("Test4", data, sizeof(data)/sizeof(int), true);
}

// Ê÷ÖÐÖ»ÓÐ1žöœáµã
void Test5()
{
    int data[] = {5};
    Test("Test5", data, sizeof(data)/sizeof(int), true);
}

void Test6()
{
    int data[] = {7, 4, 6, 5};
    Test("Test6", data, sizeof(data)/sizeof(int), false);
}

void Test7()
{
    int data[] = {4, 6, 12, 8, 16, 14, 10};
    Test("Test7", data, sizeof(data)/sizeof(int), false);
}

void Test8()
{
    Test("Test8", NULL, 0, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();

    return 0;
}

