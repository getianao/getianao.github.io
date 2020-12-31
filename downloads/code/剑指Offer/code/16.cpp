#include <iostream>
using namespace std;
/*
数值的整数次方：
不能使用库函数

思路：
需要考虑几种情况：指数为正数、零、负数。这几种情况对应的计算方法不一样。
考虑一种特殊情况：底数为0，指数不能小于0，否则需要报错。0的0次方可以为0或1，需要单独处理。

优化：
10题中的高效幂运算的算法可以用递归优化原有的循环，从而减少运算的次数。

测试用例：https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=11165&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution
{
public:
    double Power(double base, int exponent)
    {
        const double eps = 1e-6; //浮点数不能直接比较，一般负六次就够了
        if ((base >= 0 && base <= eps) || (base <= 0 && (-1) * base <= eps))
        { //底数等于0的情况
            if (exponent < 0)
            { //这里应该有一个异常
                return 0;
            }
            if (exponent == 0)
            { //人为定义
                return 1;
            }
            if (exponent > 0)
            {
                return 0;
            }
        }
        else
        {
            double pow = 1;
            //注意这里是递归的终止
            if (exponent == 0)
            {
                return 1;
            }
            if (exponent == 1)
            {
                return base;
            }
            if (exponent > 0)
            {
                // for (int i = 0; i < exponent; i++)
                // {
                //     pow = pow * base;
                // }
                pow = Power(base, exponent >> 1);
                pow = pow * pow;
                if (exponent & 0x1 == 1)
                {
                    pow = pow * base;
                }
                return pow;
            }
            else
            {
                // for (int i = 0; i < -1 * exponent; i++)
                // {
                //     pow = pow * base;
                // }
                int temp = exponent * (-1);
                pow = Power(base, temp >> 1);
                pow = pow * pow;
                if (temp & 0x1 == 1)
                {
                    pow = pow * base;
                }
                return 1.0 / pow;
            }
        }
    }
};
int main()
{
    Solution test;
    cout << test.Power(2, 3) << " " << test.Power(0, -1) << " " << test.Power(2, -3) << endl;
    return 0;
}