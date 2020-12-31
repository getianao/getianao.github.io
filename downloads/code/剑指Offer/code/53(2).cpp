#include <iostream>
#include <vector>
using namespace std;
/*
0~n-1中缺失的数字：
在一个长度为n-1的递增数组中，元素均在0~n-1之且唯一，找出那个缺失的数是多少。

思路一：求0+1+...+n-1煜数组内元素之和的差值，即为缺失的数。时间复杂度是O(n)

思路二：看见递增数组就去想二分法，通过二分法找元素大小和元素序号不同的第一个元素，时间复杂度是O(logn)。

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
                if (mid - 1 < start)
                {
                    return mid;
                }
                if (data[mid - 1] == mid - 1)
                {
                    //前一个相同
                    return mid;
                }
                else
                {
                    //前一个不同，还在前面
                    return recursiveFind(data, start, mid - 1);
                }
            }
            else
            {
                //相同，还在后面
                return recursiveFind(data, mid + 1, end);
            }
        }
    }
};
int main()
{
    int a[] = {0, 1, 2, 4};
    vector<int> data(a, a + 4);
    Solution solution;
    cout << solution.findMissedNum(data) << endl;
    return 0;
}