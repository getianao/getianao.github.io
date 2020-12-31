#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
/*
数组中只出现一次的两个数字：
数组中除了两个数字只出现一次，其他数字均出现了两次，找出这两个数字，要求时间复杂度是O(n)，空间复杂度是O(1).

思路：这里强调其他数字出现了两次，由此异或操作，如果数组中只有一个出现一次的数字，那么直接全部异或就得到答案；但是现在有两个，需要将这两个分开在两个子数组中：先全部异或，得到的数字中位上为1的表示这两个数字在这一位上不同（❗可能有多位不同，只用选取其中一位进行判断），根据这个特点，将所有数字这位为1或0分成两个子数组，子数组在全部异或即得到答案。

测试用例：https://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811?tpId=13&tqId=11193&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/

class Solution
{
public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        int xorResult = 0;
        int left = 0, right = 0;
        for (int i = 0; i < data.size(); i++)
        {
            xorResult = xorResult xor data[i];
        }
        //选取最高的为1的一位
        xorResult = pow(2, (int)(log(xorResult) / log(2)));
        for (int i = 0; i < data.size(); i++)
        {

            if ((data[i] & xorResult) == 0)
            {
                left = left xor data[i];
            }
            else
            {
                right = right xor data[i];
            }
        }
        num1[0] = left;
        num2[0] = right;
    }
};
int main()
{
    int a[] = {1, 1, 3, 6};
    vector<int> data(a, a + 4);
    Solution solution;
    int *num1 = new int;
    int *num2 = new int;
    solution.FindNumsAppearOnce(data, num1, num2);
    cout << "num1:" << *num1 << endl
         << "num2:" << *num2 << endl;
    return 0;
}