#include <iostream>
using namespace std;
/*
不用加减乘除做加法：
计算两个数之和，不能使用+-/*。

思路：没有了加减乘除，除了一些库函数，还有位运算。人类使用位运算计算加法有三步，先直接每位相加，然后记下产生进位的位，然后从低到高在它的下一位进位。

测试用例：https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=11201&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/
class Solution
{
public:
    int Add(int num1, int num2)
    {

        if (num2 == 0)
        {
            return num1;
        }
        if (num1 == 0)
        {
            return num2;
        }
        //第一步，直接加，不进位
        int a = num1 xor num2; //0+0=0，1+0=1，1+1=0
        //第二步，找进位
        int b = num1 & num2; //1+1产生进位
        b = b << 1;          //左移一位
        //第三步，加进位。
        return Add(a, b);
    }
};
int main()
{
    Solution solution;
    cout << solution.Add(1, -2) << endl;
    return 0;
}