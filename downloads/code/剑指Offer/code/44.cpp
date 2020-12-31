#include <iostream>
#include <math.h>
using namespace std;
/*
数字序列中的某一位中的数字：
数字序列012345678910111213...，求第n位（从0开始）数字时多少。

思路一：将整个序列按照数字的位数分类，可以计算出第n位所在的地方是几位数。

思路二：通过计算1、2、3...位数的位数范围来找第n位是什么数字，再确定第n位的数字是多少。

*/

class Solution
{
public:
    int FindInSequence(int index)
    {
        if (index < 0)
        {
            return -1;
        }
        if (index == 0)
        {
            return 0;
        }
        int start, num = 1;
        while (true)
        {
            //num位数结束于start
            start = startFrom(num);
            if (index > start)
            {
                num++;
            }
            else
            {
                break;
            }
        }
        start = startFrom(num - 1);
        int k; //num位的第k个数
        if ((index - start + 1) % num != 0)
        {
            //向上取整
            k = (index - start + 1) / num + 1;
        }
        else
        {
            k = (index - start + 1) / num;
        }

        int r = (index - start + 1) % num; //数的第r位
        if (r == 0)
        {
            r = num;
        }
        int result = getResult(num, k, r);
        return result;
    }
    //num位数从多少位开始
    int startFrom(int num)
    {
        if (num == 0 || num < 0)
        {
            return 0;
        }
        if (num == 1)
        {
            //包含0
            return 10;
        }
        return myPow(10, (num - 1)) * 9 * num + startFrom(num - 1);
    }

    int getResult(int num, int k, int r)
    {
        int s = myPow(10, (num - 1));
        int start = s + k - 1;
        int i = 0;
        while (i + 1 != r)
        {
            int yu = myPow(10, (num - i - 1));
            start = start % yu;
            i++;
        }
        int last = myPow(10, (num - i - 1));
        return start / last;
    }

    int myPow(int a, int b)
    {

        int i = 1;
        if (b == 0)
        {
            return 1;
        }
        while (i < b)
        {
            a = a * a;
            i++;
        }
        return a;
    }
};

int main()
{
    Solution solution;
    cout << solution.FindInSequence(1002) << endl;
    return 0;
}