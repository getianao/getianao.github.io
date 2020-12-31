#include <iostream>
#include <vector>
using namespace std;
/*
和为s的连续正数序列：
打印所有和为s的连续正数序列。

思路：思想和前面一题相似，但这次不再给出数组，而是自己控制数组，初始化数组为{1,2}，两个指针分别指向数组头和尾，如果数组中元素之和小于s，则按顺序增加一个最大元素，如果大于s，则删除一个最小元素。直到最小元素等于(s+1)/2为止（(s-1)/2仍有可能符合要求）

测试用例：https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?tpId=13&tqId=11194&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/
class Solution
{
public:
    vector<vector<int> > FindContinuousSequence(int sum)
    {
        vector<vector<int> > result;
        vector<int> array;
        array.push_back(1);
        array.push_back(2);
        while (array[0] != (sum + 1) / 2)
        {
            int s = calculateVector(array);
            if (s == sum)
            {
                result.push_back(array);
                array.push_back(array[array.size() - 1] + 1);
            }
            else
            {
                if (s > sum)
                {
                    vector<int>::iterator it = array.begin();
                    array.erase(it);
                }
                else
                {
                    array.push_back(array[array.size() - 1] + 1);
                }
            }
        }
        return result;
    }

    int calculateVector(vector<int> array)
    {
        int sum = 0;
        for (int i = 0; i < array.size(); i++)
        {
            sum += array[i];
        }
        return sum;
    }
};
int main()
{
    vector<vector<int> > result;
    Solution solution;
    result = solution.FindContinuousSequence(15);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}