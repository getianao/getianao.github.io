#include <iostream>
using namespace std;
/*
斐波那契数列:
也叫青蛙跳台阶问题（考察建模能力）

思路一：
递归的思想：根据f(n)=f(n-1)+f(n-2)写出递归公式。
时间复杂度是O(2^n)。

思路二：
循环的思想：按照我们人计算斐波那契数列的方法，通过循环不断的累加，这样就解决了递归中重复的数据没有被利用的问题。
时间复杂度是O(n)。

思路三：
通过高效幂运算公式计算：首先了解一个公式
[F(n+1) F(n)]    [1  1 ]^n
|           |   =|     |
[F(n) F(n-1)]    [1  0 ]
这个公式将问题转化为乘方，然后通过乘方的高效幂运算的性质：
    |a^(n/2)*a^(n/2) n为偶数
a^n=|
    |a^((n-1)/2)*a^((n-1/)2)*a n为奇数
即可通过递归计算处矩阵的乘方。
*/
class Solution
{
public:
    struct matrix
    {
        int a11, a12, a21, a22;
    };
    matrix mul(matrix m1, matrix m2) //矩阵乘法
    {
        return {
            m1.a11 * m2.a11 + m1.a12 * m2.a21, m1.a11 * m2.a12 + m1.a12 * m2.a22,
            m1.a21 * m2.a11 + m1.a22 * m2.a21, m1.a21 * m2.a12 + m1.a22 * m2.a22};
    }
    matrix matrixPow(matrix m, int n)
    {
        if (n == 0) //矩阵的0次方是单位矩阵
        {
            return {1, 0,
                    0, 1};
        }
        matrix m2 = matrixPow(m, n / 2); //m2是m的⌊n/2⌋次幂
        m2 = mul(m2, m2);
        if (n % 2 == 1) //为奇
        {
            m2 = mul(m2, m);
        }
        return m2;
    }
    int Fibonacci(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        matrix m = {1, 1, 1, 0};
        return matrixPow(m, n - 1).a11;
    }
};
int main()
{
    Solution test;
    cout << test.Fibonacci(6) << endl;
    return 0;
}