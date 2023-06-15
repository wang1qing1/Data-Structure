#include<iostream>
#include<map>
using namespace std;
//ºÙ÷¶
int fib(map<int, int> fomap, int n)
{
    int ppre;//fib(n-2);
    if (fomap.find(n - 2) == fomap.end())
    {
        ppre = fib(fomap, n - 2);
        fomap.insert({ n - 2,ppre });
    }
    else
    {
        ppre = fomap[n - 2];
    }
    int pre;//fib(n-1);
    if (fomap.find(n - 1) == fomap.end())
    {
        pre = fib(fomap, n - 1);
        fomap.insert({ n - 1,pre });
    }
    else
    {
        pre = fomap[n - 1];
    }
    fomap.insert({ n,pre + ppre });
    return pre + ppre;
}

int main()
{
    int n;
    cin >> n;
    map<int, int> fomap;
    fomap[1] = 1;
    fomap[2] = 1;
    cout << fib(fomap, n);

    return 0;
}