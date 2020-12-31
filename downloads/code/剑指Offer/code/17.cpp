#include <iostream>
#include <string.h>
using namespace std;
/*
打印从1到最大的n位数：
注意n位数可能是很大的数。

思路一：用字符串来存储数字，需要一个字符串加一的算法和打印字符串的函数。

思路二：依然是用字符串来存储，但不是用每次加一的方法；如果把从1到最大的n位数前面补上0，使之都成为n位字符串，它们其实就是n个0~9数字的全排列。全排列可以用递归来实现。
每一层递归尝试给某一位赋予0~9的值，然后进去下一层递归；当到达第n层递归后停止。

*/

class Solution
{
public:
    void printNDigital(int n)
    {
        if (n <= 0)
        {
            return;
        }
        char *str = new char[n + 1];
        memset(str, '0', sizeof(char) * n);
        str[n] = '\0';
        while (increment(str))
        {
            printNstr(str);
        }
    }

    bool increment(char *str)
    {
        int strLength = strlen(str);
        int nTakeOver = 0;                       //进位
        int sum = 0;                             //一位的数值
        for (int i = strLength - 1; i >= 0; i--) //从数字的最低位开始
        {
            sum = str[i] - '0' + nTakeOver;
            if (i == strLength - 1)
            {
                sum++;
            }
            if (sum >= 10)
            {
                if (i == 0)
                {
                    return false;
                }
                nTakeOver = 1;
                str[i] = sum - 10 + '0';
            }
            else
            {
                nTakeOver = 0;
                str[i] = sum + '0';
                return true; //前面的数位没有变化
            }
        }
    }
    void printNstr(char *str)
    {
        bool isBegin = false;
        int strLength = strlen(str);
        for (int i = 0; i < strLength; i++)
        {
            if (isBegin == false)
            {
                if (str[i] == '0')
                {
                    continue;
                }
                else
                {
                    cout << str[i];
                    isBegin = true;
                    continue;
                }
            }
            else
            {
                cout << str[i];
            }
        }
        cout << endl;
    }
};

class Solution2
{
public:
    void printNDigital(int n)
    {
        if (n <= 0)
        {
            return;
        }
        char *str = new char[n + 1];
        memset(str, '0', sizeof(char) * n);
        str[n] = '\0';
        for (int i = 0; i < 10; i++)
        {
            str[0] = '0' + i;
            printNDigitalRecursive(str, 1, strlen(str));
        }
    }

    void printNDigitalRecursive(char *str, int index, int strLength)
    {
        if (index == strLength)
        {
            printNstr(str);
            return;
        }
        else
        {
            for (int i = 0; i < 10; i++)
            {
                str[index] = '0' + i;
                printNDigitalRecursive(str, index + 1, strlen(str));
            }
        }
    }

    void printNstr(char *str)
    {
        bool isBegin = false;
        int strLength = strlen(str);
        for (int i = 0; i < strLength; i++)
        {
            if (isBegin == false)
            {
                if (str[i] == '0')
                {
                    continue;
                }
                else
                {
                    cout << str[i];
                    isBegin = true;
                    continue;
                }
            }
            else
            {
                cout << str[i];
            }
        }
        cout << endl;
    }
};
int main()
{
    Solution2 test;
    test.printNDigital(2);
    return 0;
}