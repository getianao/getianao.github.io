#include <iostream>
using namespace std;
/*
跳台阶：
每次可以跳上1级台阶，也可以跳上2级，跳上n阶台阶有多少种跳法。

思路：递归的思想：

测试用例：https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=11161&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/

class Solution
{
public:
    int jumpFloor(int number)
    {
        if (number == 0)
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
        return jumpFloor(number - 1) + jumpFloor(number - 2);
    }
};
int main()
{
    Solution solution;
    cout << solution.jumpFloor(5) << endl;
    return 0;
}