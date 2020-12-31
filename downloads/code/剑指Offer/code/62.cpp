#include <iostream>
using namespace std;
/*
圆圈中最后剩下的数字：
0~n-1的n个数字排成一个圆圈，从0开始计数，每次从中删掉第m个元素，求最后剩下的元素。
即约瑟夫环问题。

思路一：同一个数组标记是否被删除，然后按照题目意思直接遍历。

思路二：递归，找到这么一个递归公式f(n,m)，表示还剩n个数字时每次删除m位元素最后剩下的值；第一次删除的是k=(m-1)%n位元素，即剩下{0,1,2,...,k-1,k+1,...,n-1}，，记作f'(n-1,m)，下次循环时从k+1开始计数，所以应该是{k+1,...,n-1,0,1,...,k-1}n-2个元素，记作f(n-1,m)即正常的编号。f(n,m)=f'(n-1,m)
构建这样一个映射关系，从圆圈中的编号映射到正常编号：
k+1->0，
k+2->1，
……
n-1->n-k-2
0->n-k-1，
1->n-k-1,
……
k-1->n-2
这样的映射即为p(x)=(x-k-1)%n。得到逆映射p^-1(x)=(x+k+1)%n，从正常编号映射到原来圆圈中的编号。所以f'(n-1,m)=p^-1(f(n-1,m))=(f(n-1,m)+k+1)%n，因为k=(m-1)%n，(k+1)%n=m%n，所有哦f(n,m)=f'(n-1,m)=p^-1(f(n-1,m))=(f(n-1,m)+k+1)%n=(f(n-1,m)+m)%n
所以得到
f(n,m)=|-- 0              (n=1时)
      |-- (f(n-1,m)+m)%n  (n>1时)

测试用例：
*/

class Solution
{
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n == 0)
        {
            return -1;
        }
        if (n == 1)
        {
            return 0;
        }
        else
        {
            return (LastRemaining_Solution(n - 1, m) + m) % n;
        }
    }
};
int main()
{
    Solution solution;
    cout << solution.LastRemaining_Solution(5, 3) << endl;
    return 0;
}