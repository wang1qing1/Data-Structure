#include<iostream>
#include<vector>
using namespace std;
int sum(int n, int* arr)
{
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        s += arr[i];
    }
    return s;
}
int main()
{
    int n;
    cin >> n;

    //f(n)代表到达第n层台阶
    //f(n)=f(n-1)+f(n-2)+f(n-3)....fun(1)+1;
    int arr[n + 1];
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        arr[i] = sum(i - 1, arr) + 1;
    }
    cout << arr[n];

    return 0;
}
// 64 位输出请用 printf("%lld")