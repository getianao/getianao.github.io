#include <iostream>
using namespace std;
/*
变态跳台阶：
每次可以跳上1级台阶，也可以跳上2级，...，也可以跳上n级，跳上n阶台阶有多少种跳法。

思路：递归的思想；

测试用例：https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=11161&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/

class Solution
{
public:
    int jumpFloorII(int number)
    {
        if (number == 0)
        {
            return 1;
        }
        if (number == 1)
        {
            return 1;
        }
        int sum = 0;
        for (int i = 1; i <= number; i++)
        {
            sum += jumpFloorII(number - i);
        }
        return sum;
    }
};
int main()
{
    Solution solution;
    cout << solution.jumpFloorII(2) << endl;
    return 0;
}