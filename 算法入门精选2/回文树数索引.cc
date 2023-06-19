#include <iostream>
#include<algorithm>
#include<string>
using namespace std;
//回文串“abcba”
//“abccda”双指针前(i)后(j)往中间遍历，如果遇到arr[i]!=arr[j]。我们尝试删除i或者j位置字符
bool ispalindrome(string& str, int& left, int& right)
{
    while (left < right)
    {
        if (str[left] != str[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        int left = 0;
        int right = str.length() - 1;
        if (ispalindrome(str, left, right))
        {
            cout << -1 << endl;
        }
        else
        {

            str.erase(str.find(str[left]), 1);//string::erase(pos,n)删除指定位置pos开始的n个字符。
            int ltmp = 0;
            int rtmp = str.length() - 1;
            if (ispalindrome(str, ltmp, rtmp))
            {
                cout << left << endl;
            }
            else {
                cout << right << endl;
            }
        }
    }
}
// 64 位输出请用 printf("%lld")