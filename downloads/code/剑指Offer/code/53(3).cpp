#include <iostream>
#include <vector>
using namespace std;
/*
数组中数值和下标相等的元素：
单调递增数组中的元素是唯一的，任意其中一个数值和下标相等的元素。

思路一：顺序查找。

思路二：二分查找。注意是单调的，用二分法查找，如果不是，下标大于数值，则在后面；下标小于数值，则在前面。

*/
class Solution
{
public:
    int findMissedNum(vector<int> data)
    {
        return recursiveFind(data, 0, data.size() - 1);
    }
    int recursiveFind(vector<int> data, int start, int end)
    {
        if (start > end)
        {
            return -1;
        }
        else
        {
            int mid = start + (end - start + 1) / 2;
            if (data[mid] != mid)
            {
                //不同
                if (data[mid] > mid)
                {
                    //下标小于数值，前面
                    return recursiveFind(data, start, mid - 1);
                }
                if (data[mid] < mid)
                {
                    //下标大于数值，后面
                    return recursiveFind(data, mid + 1, end);
                }
            }
            else
            {

                return mid;
            }
        }
    }
};
int main()
{
    int a[] = {-3,-1, 1, 3, 5};
    vector<int> data(a, a + 5);
    Solution solution;
    cout << solution.findMissedNum(data) << endl;
    return 0;
}