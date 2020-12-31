#include <iostream>
#include <vector>
using namespace std;
/*
数组中出现次数超过一半的数字：
不存在则输出0。

思路一：直接排序再统计每个数字的出现次数，排序最低需要O(nlogn)。

思路二：如果出现次数超过一半，那么排序过的数组的中位数就一定是要找的数字。那么目标就变成找排序过的数组的中位数上数字。结合快排算法，如果选中的数字下标正好是n/2，则就是答案，否则就在它的左边或右边继续寻找。
注意：查找过程中原数组将会被修改。
❓为什么这样的算法时间为O(n)

思路三：如果出现次数超过一半，说明它出现的次数比剩下的所有其他元素都要多，遍历整个数组，记录两个数组：一个元素数据和出现次数；如果下一个元素和记录的相同，则出现次数加1，不同则减1，如果出现次数被减到0，则换成当前元素。
这种做法可行是因为到最后，要找的元素的出现次数一定不会被减到0。

❓两种方法一定要做检查，看最后是不是出现了一般次数以上

测试用例：https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&tPage=2&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

*/

class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if (numbers.size() == 0)
        {
            return 0;
        }
        int num = numbers[0], s = 1;
        for (int i = 1; i < numbers.size(); i++)
        {
            //如果结果为0，保存的是它的下一个数字
            if (s == 0)
            {
                num = numbers[i];
                s++;
                continue;
            }
            if (numbers[i] == num)
            {
                s++;
                continue;
            }
            else
            {
                s--;
                continue;
            }
        }
        if (s == 0)
        {
            return 0;
        }
        else
        {
            if (check(num, numbers) == true)
            {
                return num;
            }
            else
            {
                return false;
            }
        }
    }

    bool check(int num, vector<int> numbers)
    {
        int time = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == num)
            {
                time++;
            }
        }
        if (2 * time > numbers.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    int a[] = {1, 2, 3, 2, 4, 3, 5, 2, 3};
    vector<int> input(a, a + 9);
    Solution solution;
    cout << solution.MoreThanHalfNum_Solution(input) << endl;
    return 0;
}