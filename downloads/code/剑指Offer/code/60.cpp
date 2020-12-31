#include <iostream>
#include <map>
using namespace std;
/*
n个骰子的点数：
n个骰子上面的数字和为s，打印出所有可能出现s的值及其概率。
最小值为6，最大值为6n。将6个骰子看作不一样的，一共有6^n种情况。

思路一：递归：将n个骰子看作1个和剩下n-1个，一个可能出现1~6的6种情况，剩下n-1出现n-1~6(n-1)的5(n-1)+1种情况。

思路二：遍历：用两个数组来交替求解，n个骰子的k点的种数是n-1个骰子的k-1点、k-2点……k-6点的种数之和；求解时要注意k-1……k-6的情况在n-1中是否存在。
*/
class Solution
{
public:
    //n个骰子的点数及概率
    map<int, int> getP(int n, map<int, int> m)
    {
        if (n == 1)
        {
            m[1] = 1;
            m[2] = 1;
            m[3] = 1;
            m[4] = 1;
            m[5] = 1;
            m[6] = 1;
            return m;
        }
        //计算后n-1骰子的情况
        m = getP(n - 1, m);
        //再加上这一个骰子的情况
        map<int, int> mm; //原情况
        map<int, int>::iterator it = m.begin();
        for (; it != m.end(); it++)
        {
            for (int i = 1; i <= 6; i++)
            {
                int value = (it->first) + i;
                map<int, int>::iterator isFindOld = m.find(value);
                map<int, int>::iterator isFindNew = mm.find(value);
                if (isFindNew == mm.end())
                {
                    //新的值
                    if (isFindOld == m.end())
                    {
                        mm[value] = 1;
                    }
                    else
                    {
                        mm[value] = m[value];//❗这里不需要+1
                    }
                }
                else
                {
                    //旧的值
                    mm[value] = mm[value] + 1;
                }
            }
        }
        return mm;
    }
};
class Solution2
{
public:
    //n个骰子的点数及概率
    int *getP(int n)
    {
        int *p = new int[6 * n + 1];
        int *pp = new int[6 * n + 1];
        //i表示i个骰子
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
            {
                p[1] = 1;
                p[2] = 1;
                p[3] = 1;
                p[4] = 1;
                p[5] = 1;
                p[6] = 1;
                continue;
            }
            if (i % 2 == 1)
            {
                //j表示i个骰子的点数范围为i~6i
                for (int j = i; j <= 6 * i; j++)
                {
                    int sum = 0;
                    for (int k = 1; k <= 6; k++)
                    {
                        if ((j - k >= i - 1) && (j - k <= 6 * (i - 1)))
                        {
                            sum = sum + pp[j - k];
                        }
                    }
                    p[j] = sum;
                }
            }
            else
            {
                //j表示i个骰子的点数范围为i~6i
                for (int j = i; j <= 6 * i; j++)
                {
                    int sum = 0;
                    for (int k = 1; k <= 6; k++)
                    {
                        if ((j - k >= i - 1) && (j - k <= 6 * (i - 1)))
                        {
                            sum = sum + p[j - k];
                        }
                    }
                    pp[j] = sum;
                }
            }
            if (n % 2 == 1)
            {
                return p;
            }
            else
            {
                return pp;
            }
        }
    }
};
int main()
{
    map<int, int> m;
    Solution solution;
    m = solution.getP(2, m);
    map<int, int>::iterator it = m.begin();
    for (; it != m.end(); it++)
    {
        cout << it->first << ":" << it->second << endl;
    }
    cout << endl;
    Solution2 solution2;
    int n = 2;
    int *result = new int[6 * n + 1];
    result = solution2.getP(n);
    for (int i = n; i <= n * 6; i++)
    {
        cout << i << ":" << result[i] << endl;
    }
    return 0;
}