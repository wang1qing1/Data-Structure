#include <iostream>
#include<algorithm>
#include<string>
using namespace std;
//���Ĵ���abcba��
//��abccda��˫ָ��ǰ(i)��(j)���м�������������arr[i]!=arr[j]�����ǳ���ɾ��i����jλ���ַ�
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

            str.erase(str.find(str[left]), 1);//string::erase(pos,n)ɾ��ָ��λ��pos��ʼ��n���ַ���
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
// 64 λ������� printf("%lld")