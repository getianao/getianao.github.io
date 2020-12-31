#include <iostream>
#include <vector>
#include <deque>
using namespace std;
/*
滑动窗口的最大值：
给定一个数组和滑动窗口的大小，输出每个滑动窗口中的最大值。

思路：使用一个双向队列来保存最大值的坐标，队列的第一个是当前窗口的最大值，当窗口滑动时，首先判断队列的第一个有没有超出窗口，超出则弹出队列，然后判断新增的元素，在列表中从后向前检查元素，如果列表中的元素更小，则将其弹出，最后将这个新增的元素添加到队列。

测试用例：https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788?tpId=13&tqId=11217&tPage=4&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/
class Solution
{
public:
    vector<int> maxInWindows(const vector<int> &num, unsigned int size)
    {
        vector<int> result;
        deque<int> dequeInt; //双端队列，存储滑动窗口中的最大值的坐标
        for (int i = 0; i < num.size(); i++)
        {

            if (!dequeInt.empty())
            {
                //❓这里直接写到if里会判断结果不对
                int aa = (i + 1 - size);
                int bb = dequeInt.front();
                if (aa > bb)
                    //超出滑动窗口范围
                    dequeInt.pop_front();
            }
            while (!dequeInt.empty() && num[i] > num[dequeInt.back()])
            {
                //在队列中从后往前找，遇到新的值更大的话，就把队列中的值出栈
                dequeInt.pop_back();
            }
            dequeInt.push_back(i);
            if (i >= size - 1)
            {
                result.push_back(num[dequeInt.front()]);
            }
        }
        return result;
    }
};
int main()
{
    Solution solution;
    int a[] = {16, 14, 12, 10, 8, 6, 4};
    vector<int> num(a, a + 7);
    vector<int> result = solution.maxInWindows(num, 5);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}