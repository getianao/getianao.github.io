
#include <iostream>
using namespace std;
/*
矩阵覆盖：
用2*1或1*2的小矩形去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
输入n；

思路：递归

测试用例：https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?tpId=13&tqId=11163&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/
class Solution
{
public:
    int rectCover(int number)
    {
        if (number <= 0)
        {
            return 0;
        }
        if (number == 1)
        {
            return 1;
        }
        if (number == 2)
        {
            return 2;
        }
        return rectCover(number - 2) + rectCover(number - 1);
    }
};
int main()
{
    Solution solution;
    cout << solution.rectCover(4) << endl;
    return 0;
}