#include <iostream>
#include <cmath>
using namespace std;
/*
剪绳子：
给定一条长度为n的绳子，将它剪成若干段（大于一），求这几段绳子长度乘积的最大值。

思路一：
利用动态规划的思想，剪绳子的步骤可以分解为剪第一刀和剪之后的几刀，那么可以得到这个公式：f(n)=max{f(i)*f(n-i)}，从而实现了动态规划。

思路二：
使用下面的贪婪方法：当绳子的长度大于5时，尽可能多的剪成长度为3的绳子，其余的情况单独讨论。可以证明剪成3和剪成2来比较，剪成3更好：3(n-3)>=2(n-2),并且剪的3越多越大。注意在剩下一段为4时不能3、1分，而其他的情况可以和这种分法合并。
*/

class Solution
{
public:
    int maxCuttingDP(int length)
    {
        //对于length等于1、2、3的情况，并不等于max数组中的赋值，因为要求至少分为两段，而max中可以分为一段
        if (length <= 1)
        {
            return 0;
        }
        if (length == 2)
        {
            return 1;
        }
        if (length == 3)
        {
            return 2;
        }
        int *max = new int[length + 1];
        max[0] = 0;
        max[1] = 1;
        max[2] = 2;
        //长度从3到length的绳子的最大值
        for (int i = 3; i <= length; i++)
        {
            int temp = i; //不剪的情况
            for (int j = 1; j <= i / 2; j++)
            {
                if (max[j] * max[i - j] > temp)
                {
                    temp = max[j] * max[i - j];
                }
            }
            max[i] = temp;
        }
        return max[length];
    }

    int maxCuttingGreedy(int length)
    {
        if (length <= 1)
        {
            return 0;
        }
        if (length == 2)
        {
            return 1;
        }
        if (length == 3)
        {
            return 2;
        }
        if (length == 4) //4是一个特殊情况，要2、2分而不是3、1分
        {
            return 4;
        }
        if (length >= 5)
        {
            int max;
            if ((length - 4) % 3 == 0)
            { //最后一段为4的情况
                max = pow(3.0f, (length / 3) - 1) * 4;
                return max;
            }
            else
            {
                max = pow(3.0f, (length / 3)) * (length % 3);
                return max;
            }
        }
    }
};

int main()
{
    Solution test;
    cout << "dynamic programming: " << test.maxCuttingDP(10) << endl;
    cout << "greedy algorithm: " << test.maxCuttingGreedy(10) << endl;

    cout << "dynamic programming: " << test.maxCuttingDP(11) << endl;
    cout << "greedy algorithm: " << test.maxCuttingGreedy(11) << endl;
    return 0;
}