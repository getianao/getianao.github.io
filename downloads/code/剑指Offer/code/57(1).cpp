#include <iostream>
#include <vector>
using namespace std;
/*
和为s的两个数字：
在递增数组中找出一对和为s的两个元素，如果有多对，输出乘积最小的。

思路：注意递增数组的特点！用两个指针指向数组的第一个元素和最后一个元素，如果此时两个元素之和大于s，则移动后面一个元素，否则移动前面一个元素。

测试用例：https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b?tpId=13&tqId=11195&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/
class Solution
{
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        vector<int> result;
        int start = 0, end = array.size() - 1;
        while (start < end)
        {
            if (array[start] + array[end] == sum)
            {
                result.push_back(array[start]);
                result.push_back(array[end]);
                return result;
            }
            if (array[start] + array[end] < sum)
            {
                start++;
            }
            if (array[start] + array[end] > sum)
            {
                end--;
            }
        }
        return result;
    }
};
int main()
{
    int a[] = {1, 2, 4, 7, 11, 15};
    vector<int> array(a, a + 6);
    vector<int> result;
    Solution solution;
    result = solution.FindNumbersWithSum(array, 15);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}