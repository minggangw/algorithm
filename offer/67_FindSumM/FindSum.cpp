#include <iostream>
#include <list>


using namespace std;

list<int> list_;

void find_factor(int sum,int n)
{
    //递归出口
    if (n <= 0 || sum <= 0)
        return;

    //输出找到的数
    if(sum == n) {
        for (list<int>::iterator iter = list_.begin(); iter != list_.end(); iter++)
            cout<<*iter<<"+";

        cout << n << endl;
    }

    list_.push_front(n);
    find_factor(sum-n, n-1);//n放在里面
    list_.pop_front();
    find_factor(sum, n-1);//n不放在里面
}

int main(int argc, char* argv[])
{
    int sum, n;
    cout << "enter the sum:";
    cin >> sum;
    cout << "enter the n number:";
    cin >> n;

    cout << "\npossible sequeces:" << endl;

    find_factor(sum, n);

    return 0;
    }
