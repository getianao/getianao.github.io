#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
扑克牌中的顺子：
A看作1，J看作11，Q看作12，K看作12，大小王可以看作任意牌（记作0），判断给出的序列能否排列成顺子。

思路：首先将数组排序，记录下0的数量，然后查找其他数字之间的剑客总数，与0的总数作比较。过程中出现对子，则不可能为顺子。

测试用例：
*/
class Solution
{
public:
    bool IsContinuous(vector<int> numbers)
    {
        if (numbers.size() == 0)
        {
            return false;
        }
        if (numbers.size() == 1)
        {
            return true;
        }
        sort(numbers.begin(), numbers.end());
        int zeroNum = getZeroNum(numbers);
        //统计间隔
        int interval = 0;
        for (int i = zeroNum; i < numbers.size() - 1; i++)
        {
            if (numbers[i + 1] == numbers[i])
            {
                return false;
            }
            if (numbers[i + 1] - numbers[i] > 1)
            {
                interval += numbers[i + 1] - numbers[i] - 1;
            }
        }
        if (interval > zeroNum)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    //大小王数量
    int getZeroNum(vector<int> numbers)
    {
        int sum = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == 0)
            {
                sum++;
            }
        }
        return sum;
    }
};
int main()
{
    Solution solution;
    int a[] = {1, 3, 2, 6, 4};
    vector<int> input(a, a + 5);
    if (solution.IsContinuous(input) == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}