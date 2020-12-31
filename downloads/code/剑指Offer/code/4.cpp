#include <iostream>
#include <vector>
using namespace std;

/*
二维数组中的查找：
二维数组每行每列都满足从左到右、从上到下为递增顺序，要判断这个数组中是否包含一个整数。

思路：选定二维数组中的一个元素来和要查找的数字进行比较，通过每次比较的结果（大于、小于、等于）来减少查找的范围。以选择中间一个元素来比较为例，如果要查找的数字更小，可以把 + 号区域排除，如果要查找的数字更大，可以把 + 号区域排除。可见，选区比较的点的位置很重要，这样选择会导致下一次比较无从下手。

- - - - -
- - - - -
- - * + +
- - + + +
- - + + +

+ + + - -
+ + + - -
+ + * - -
- - - - -
- - - - -

但是选择右上角或左下角的元素可以，以左下角为例，如果要查找的元素更大，可以排除所在列，如果要查找的元素更小，可以排除所在行，这样就可以在保证每次筛选方法不变的情况下减少查找范围。

测试用例：https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution
{
public:
    bool Find(int target, vector<vector<int> > array) //这里>>之间应有空格，否则会被认为是运算符
    {
        if (array.size() == 0)
        {
            return false;
        }
        int x = 0, y = array.size() - 1;

        while (x < array[0].size() && y >= 0)
        {
            //在循环内判断会产生段错误，不知为何
            // while (true)
            // {
            //     if (x > array[0].size() - 1 || y < 0)
            //     { //没有找到的终止条件是超出数组范围
            //         return false;
            //     }
            int temp = array[y][x];
            if (temp == target)
            {
                return true;
            }
            if (temp > target)
            {
                y--;
            }
            else
            {
                x++;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int> > numbers(4, vector<int>(5));
    int b[4][5] = {{1, 2, 8, 9, 10}, {2, 4, 9, 10, 12}, {4, 7, 10, 11, 13}, {6, 8, 10, 11, 15}};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            numbers[i][j] = b[i][j];
        }
    }
    Solution test;
    if (test.Find(14, numbers))
    {
        cout << "find!" << endl;
    }
    else
    {
        cout << "not find." << endl;
    }
    return 0;
}