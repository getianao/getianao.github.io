#include <iostream>
#include <set>
using namespace std;
/*
丑数：
因数只包含2、3、5的数称为丑数，1作为第一个丑数。求第n个丑数。

思路一：先后尝试用2，3，5去整除，最后剩下1则为丑数。缺点是每个整数都要进行判断。

思路二：维护一个数组，里面存储从小到大的丑数，用三个指针指向这个数组中分别乘2、3、5刚刚超过数组中的最大丑数的位置。每次比较这些位置分别乘2、3、5后的最小值，添加进数组，然后再更新指针（所有指针都要更新，因为可能会出现像3*2、2*3添加6的情况）。

测试用例：https://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b?tpId=13&tqId=11186&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

*/
class Solution
{
public:
    int GetUglyNumber_Solution(int index)
    {
        int *uglyMap = new int[index];
        uglyMap[0] = 1;
        int count = 1;
        int t2 = 0, t3 = 0, t5 = 0;
        while (count < index)
        {
            int next2 = uglyMap[t2] * 2;
            int next3 = uglyMap[t3] * 3;
            int next5 = uglyMap[t5] * 5;
            if (next2 <= next3 && next2 <= next5)
            {
                uglyMap[count++] = next2;
            }
            else if (next3 <= next2 && next3 <= next5)
            {
                uglyMap[count++] = next3;
            }
            else if (next5 <= next2 && next5 <= next3)
            {
                uglyMap[count++] = next5;
            }
            while (true)
            {
                if (uglyMap[t2] * 2 > uglyMap[count - 1])
                {
                    break;
                }
                t2++;
            }
            while (true)
            {
                if (uglyMap[t3] * 3 > uglyMap[count - 1])
                {
                    break;
                }
                t3++;
            }
            while (true)
            {
                if (uglyMap[t5] * 5 > uglyMap[count - 1])
                {
                    break;
                }
                t5++;
            }
        }
        return uglyMap[index - 1];
    }
};
int main()
{
    Solution solution;
    cout << solution.GetUglyNumber_Solution(1500) << endl;
    return 0;
}
