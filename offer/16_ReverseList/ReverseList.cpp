// ReverseList.cpp : Defines the entry point for the console application.
//

// ¡¶œ£ÖžOffer¡ª¡ªÃûÆóÃæÊÔ¹ÙŸ«œ²µäÐÍ±à³ÌÌâ¡·ŽúÂë
// Öø×÷ÈšËùÓÐÕß£ººÎº£ÌÎ

#include <cstddef>
#include <cstdio>
#include <cstdlib>

#include "List.h"

ListNode* ReverseList(ListNode* pHead)
{
    ListNode* pReversedHead = NULL;
    ListNode* pNode = pHead;
    ListNode* pPrev = NULL;
    while(pNode != NULL)
    {
        ListNode* pNext = pNode->m_pNext;

        if(pNext == NULL)
            pReversedHead = pNode;

        pNode->m_pNext = pPrev;

        pPrev = pNode;
        pNode = pNext;
    }

    return pReversedHead;
}

// ====================²âÊÔŽúÂë====================
ListNode* Test(ListNode* pHead)
{
    printf("The original list is: \n");
    PrintList(pHead);

    ListNode* pReversedHead = ReverseList(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

// ÊäÈëµÄÁŽ±íÓÐ¶àžöœáµã
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// ÊäÈëµÄÁŽ±íÖ»ÓÐÒ»žöœáµã
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// ÊäÈë¿ÕÁŽ±í
void Test3()
{
    Test(NULL);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}

