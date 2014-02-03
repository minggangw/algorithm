#pragma once
#include <stack>
#include <exception>
#include <stdexcept>
#include <string>

using namespace std;

template <typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);
    
    // ÔÚ¶ÓÁÐÄ©Î²ÌíŒÓÒ»žöœáµã
    void appendTail(const T& node);

    // ÉŸ³ý¶ÓÁÐµÄÍ·œáµã
    T deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T> CQueue<T>::CQueue(void)
{
}

template <typename T> CQueue<T>::~CQueue(void)
{
}

template<typename T> void CQueue<T>::appendTail(const T& element)
{
    stack1.push(element);
} 

template<typename T> T CQueue<T>::deleteHead()
{
    if(stack2.size()<= 0)
    {
        while(stack1.size()>0)
        {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    if(stack2.size() == 0)
        throw std::runtime_error("test");

    T head = stack2.top();
    stack2.pop();

    return head;
}

int main()
{
    CQueue<int> q;
    q.appendTail(100);
    printf("head is %d\n", q.deleteHead());
    
    return 0;
}
