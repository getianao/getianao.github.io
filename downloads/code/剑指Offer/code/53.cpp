#include <iostream>
#include <vector>
using namespace std;
/*
数字在排序数组中出现的次数：

思路一：直接在数组中顺序查找。

思路二：利用排序数组的特点，通过二分查找找第一个k和最后一个k.

测试用例：nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&tqId=11190&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/
class Solution
{
public:
    int GetNumberOfK(vector<int> data, int k)
    {
        int f = findFirstNum(data, k, 0, data.size() - 1);
        int l = findLastNum(data, k, 0, data.size() - 1);
        if (f == -1)
        {
            return 0;
        }
        else
        {
            return l - f + 1;
        }
    }

    int findFirstNum(vector<int> data, int k, int start, int end)
    {
        if (start > end)
        {
            return -1;
        }
        int length = end - start + 1;
        if (length == 0)
        {
            return -1;
        }
        else
        {
            int mid = start + length / 2;
            if (data[mid] == k)
            {
                if (mid - 1 < start)
                {
                    return mid;
                }
                if (data[mid - 1] == k)
                {
                    //还在前面
                    return findFirstNum(data, k, start, mid - 1);
                }
                else
                {
                    //这就是第一个k
                    return mid;
                }
            }
            else
            {
                if (data[mid] > k)
                {
                    //还在前面
                    return findFirstNum(data, k, start, mid - 1);
                }
                else
                {
                    //还在后面
                    return findFirstNum(data, k, mid + 1, end);
                }
            }
        }
    }

    int findLastNum(vector<int> data, int k, int start, int end)
    {
        if (start > end)
        {
            return 0;
        }
        int length = end - start + 1;
        if (length == 0)
        {
            return -1;
        }
        else
        {
            int mid = start + length / 2;
            if (data[mid] == k)
            {
                if (mid + 1 > end)
                {
                    return mid;
                }
                if (data[mid + 1] == k)
                {
                    //还在后面
                    return findLastNum(data, k, mid + 1, end);
                }
                else
                {
                    //这就是最后一个k
                    return mid;
                }
            }
            else
            {
                if (data[mid] > k)
                {
                    //还在前面
                    return findFirstNum(data, k, start, mid - 1);
                }
                else
                {
                    //还在后面
                    return findFirstNum(data, k, mid + 1, end);
                }
            }
        }
    }
};
int main()
{
    Solution solution;
    int a[] = {1, 2, 3, 3, 3, 3, 4, 5};
    vector<int> data(a, a + 8);
    cout << solution.GetNumberOfK(data, 7);
    return 0;
}