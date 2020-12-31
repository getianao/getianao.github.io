#include <iostream>
#include <vector>
using namespace std;
/*
连续子数组的最大和：
一个数组有多个子数组，求元素的和最大的子数组的和是多少。

思路一：利用数组的规律；在数组中从前往后加，如果累加结果成负数了，则之前的（包括这一个）元素都不可能在要求的子数组中，然后从新开始累加，累加过程中记录最大值。

思路二：动态规划；f(i)表示以第i个元素结尾的子数组的最大和，则有
f(i)=|--  pData(i)         当i=0或f(i-1)<0时
    |-- f(i-1)+pData(i)    当i>0且f(i-1)>0时


*/
class Solution
{
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        if (array.size() == 0)
        {
            return 0;
        }
        vector<int> f(array.size());
        for (int i = 0; i < array.size(); i++)
        {
            if (i == 0 || (i > 0 && f[i - 1] < 0))
            {
                f[i] = array[i];
                continue;
            }

            if (i > 0 && f[i - 1] > 0)
            {
                f[i] = array[i] + f[i - 1];
                continue;
            }
        }
        int max = f[0];
        for (int i = 1; i < f.size(); i++)
        {
            if (max < f[i])
            {
                max = f[i];
            }
        }
        return max;
    }
};
int main()
{
    Solution solution;
    int a[] = {1, -2, 3, 10, -4, 7, 2, -5};
    vector<int> input(a, a + 8);
    cout << solution.FindGreatestSumOfSubArray(input) << endl;
    return 0;
}