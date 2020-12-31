#include <iostream>
#include <queue>
using namespace std;
/*
数据流中的中位数：
奇数个数据中位数时排序之后中间的数值，偶数个数据时排序后中间两个数值的平均数。

思路：将数据流分成两部分，左边的数据小于右边的数据，左边的数据由大顶堆实现，右边的数据由小顶堆实现，这样左右均没有排序，但是我还是知道中间的数据元素。
数据插入过程中要保持两边的数据数量平衡。

测试用例：https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1?tpId=13&tqId=11216&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution
{
public:
    priority_queue<int, vector<int>, less<int> > left;     //升序队列，小顶堆
    priority_queue<int, vector<int>, greater<int> > right; //降序队列，大顶堆

    void Insert(int num)
    {
        //大于左边的要放在右边
        if (left.size() == 0 || left.top() > num)
        {
            left.push(num);
        }
        else
        {
            right.push(num);
        }

        if (left.size() == right.size() + 2)
        {
            //左边的多2
            right.push(left.top());
            left.pop();
        }

        if (left.size() + 1 == right.size())
        {
            //始终保持左边多于等于右边
            left.push(right.top());
            right.pop();
        }
    }

    double GetMedian()
    {
        if (left.size() + right.size() == 0)
        {
            return 0;
        }
        if ((left.size() + right.size()) % 2 == 1)
        {
            //奇数
            return left.top();
        }
        else
        {
            double d = (left.top() + right.top()) / 2.0;
            return d;
        }
    }
};
int main()
{
    Solution solution;
    solution.Insert(5);
    solution.Insert(2);
    solution.Insert(3);
    solution.Insert(4);
    solution.Insert(1);
    solution.Insert(6);
    solution.Insert(7);
    cout << solution.GetMedian() << endl;
    return 0;
}