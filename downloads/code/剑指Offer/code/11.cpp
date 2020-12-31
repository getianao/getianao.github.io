#include <iostream>
#include <vector>
using namespace std;
/*
旋转数组的最小数字：
将一个非递减的数组向前循环移动几位，找出该数组的最小元素。

思路一：
最直观的解法就是从前往后依次找，遇到后面的元素小于前面的元素，则后面的元素就为最小元素。若不存在这样的情况，第一个元素为最小的元素。
时间复杂度为O(n)

思路二：
旋转数组可以兼做两个连接的非递减数组，数组在一定程度上来说也是有序的,前一个数组的元素要大于后一个数组的元素，而我们要找的最小元素就是第二个非递减序列的第一个元素。借用二分查找的思想，用一个指针a指向第一个元素，一个指针b指向最后一个元素，一个指针c指向 (b+a)/2 的中间元素，将c和a、b作比较：如果c大于a，则c位于前一个非递减序列，将b赋值为c；否则c位于后一个非递减序列，将a赋值为c；最后a指向前一个非递减序列的最后一个元素，b指向后一个非递减序列的第一个元素。
考虑几种特殊情况：
①旋转数组的移动位数为0，即整个数组为非递减序列。此时第一个元素为最小元素。
②前面的分类没有讨论c和a、b相等,如 10111，10111。此时不能确定中间元素属于前后哪个序列：此时顺序查找的方法。
时间复杂度是O(logn)。

测试用例：https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {

        int length = rotateArray.size();
        if (length == 0)
        {
            return 0;
        }
        int start = 0, end = length - 1;
        int middle;
        if (rotateArray[start] < rotateArray[end])
        {
            //整个数组有序
            return rotateArray[0];
        }
        while (start != end - 1)
        {
            if (start == end)
            {
                return rotateArray[end];
            }
            middle = (start + end) / 2;
            if (rotateArray[middle] == rotateArray[start] && rotateArray[middle] == rotateArray[end])
            {
                //使用顺序查找
                return findInOrder(start, end, rotateArray);
            }
            else
            {
                if (rotateArray[middle] >= rotateArray[start]) //注意要有等于
                {
                    //属于前面
                    start = middle;
                    continue;
                }
                else if (rotateArray[middle] <= rotateArray[end])
                {
                    //属于后面
                    end = middle;
                    continue;
                }
            }
        }
        return rotateArray[end];
    }
    int findInOrder(int start, int end, vector<int> rotateArray)
    {
        int result = -999;
        for (int i = start; i <= end; i++)
        {
            if (result <= rotateArray[i])
            {
                result = rotateArray[i];
            }
            else
            {
                return rotateArray[i];
            }
        }
        return rotateArray[start];
    }
};

int main()
{
    Solution test;
    vector<int> rotateArray;
    int array[] = {2};
    for (int i = 0; i < 1; i++)
    {
        rotateArray.push_back(array[i]);
    }
    cout << test.minNumberInRotateArray(rotateArray) << endl;
    return 0;
}