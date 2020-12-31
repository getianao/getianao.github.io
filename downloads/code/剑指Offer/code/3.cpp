#include <iostream>
#include <vector>
using namespace std;

/*
找出数组中重复的数字
长度为 n 的数组内元素均在 0~n-1 之间，判断是否有重复元素，有的找出任意一个重复元素

思路一：
将整个数组排序，然后扫描整个数组，比较前后两个元素。
排序的时间复杂度是log(nlogn)

思路二：
借助一个哈希表，扫描整个数组，每个元素在哈希表中查找，看是否存在于哈希表中。
扫描的时间复杂度是log(n)，但空间复杂度是log(nlogn)。

思路三：
注意到了所有数字都在 0~n-1 范围内的特点，那么可以将大小为 m 的元素放在序号为 m 的位置上，如果发现序号为 m 的位置的元素大小也为 m ，说明出现了重复元素。

测试用例：https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution1
{
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int *duplication)
    {
        if (numbers == NULL || length <= 0)
        {
            return false;
        }
        for (int i = 0; i < length; i++)
        {
            if (numbers[i] < 0 || numbers[i] > length - 1)
            {
                return false;
            }
        }
        for (int i = 0; i < length; i++)
        {
            if (numbers[i] == i)
            { //元素大小等于序号，下一个
                continue;
            }
            if (numbers[i] == numbers[numbers[i]])
            { //元素应属的位置已有相同大小的其他元素
                *duplication = numbers[i];
                return true;
            }
            else
            {
                int temp = numbers[i];
                numbers[i] = numbers[numbers[i]];
                numbers[temp] = temp;
                i--;
                continue;
            }
        }
        return false;
    }
};

/*
不修改数组查找重复的数字
长度为 n+1 的数组内元素均在 1~n 之间（至少有一个元素是重复的），在不修改原数组的情况下找出一个重复元素

思路一：
借助辅助空间，新建一个等大小的数组，复制的过程让元素落入对应的位置中。
时间复杂度和空间复杂度均为log(n)。

思路二；
借助二分查找的思想，每次将查找范围二分为 1~n/2 和 n/2+1~n ，分别查找每个范围的元素个数，如果 1~n/2 范围的元素个数大于 n/2，则说明这个区间有重复元素。
时间复杂度是log(nlogn)
*/
class Solution2
{
public:
    int duplicate(const int numbers[], int length)
    {
        int start = 0, end = length - 2;
        while (true)
        {
            int middle = start + (end - start + 1) / 2 - 1;
            int count = countRange(numbers, length, start, middle);
            if (middle == start && count > 1)
            {
                return start;
            }
            if (count > middle - start + 1)
            {
                end = middle;
            }
            else
            {
                start = middle + 1;
            }
        }
        return -1;
    }
    int countRange(const int *numbers, int length, int start, int end)
    {
        int count = 0;
        for (int i = 0; i < length; i++)
        {
            if (numbers[i] >= start && numbers[i] <= end)
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution1 test1;
    int numbers[] = {2, 3, 1, 0, 2, 5, 3};
    int length = 7;
    int *duplication;
    if (test1.duplicate(numbers, length, duplication))
    {
        cout << "Solution1: " << *duplication << " is duplicate" << endl;
    }
    else
    {
        cout << "Solution1: "
             << "isn't duplicate" << endl;
    }

    Solution2 test2;
    int numbers2[] = {2, 3, 5, 4, 3, 2, 6, 7};
    int length2 = 8;
    cout << "Solution2: " << test2.duplicate(numbers2, length2) << " is duplicate" << endl;
    return 0;
}