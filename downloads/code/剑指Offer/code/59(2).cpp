#include <iostream>
#include <deque>
#include <vector>
using namespace std;
/*
队列的最大值：
定义一个队列，max函数得到队列中的最大值，push_back()和pop_front()的时间复杂度都是1

思路：和上题相似，队列可以看作是一个滑动窗口，push_back()相当于窗口值向后增大1（双向队列size+1并添加新元素），pop_front()相当于窗口值-1（双向队列size-1）。

*/
class Solution
{
public:
    vector<int> v;
    deque<int> d;
    int max()
    {
        return v[d.front()];
    }

    void push_back(int a)
    {
        //放入队列
        v.push_back(a);
        //是否需要更新双向队列
        while (!d.empty() && a > v[d.back()])
        {
            //在队列中从后往前找，遇到新的值更大的话，就把队列中的值出栈
            d.pop_back();
        }
        d.push_back(v.size() - 1);
    }
    void pop_front()
    {
        //删除队列中第一个元素
        vector<int>::iterator it = v.begin();
        v.erase(it);
        //所有双向队列中的元素需要减1
        deque<int>::iterator dit = d.begin();
        for (; dit != d.end(); dit++)
        {
            (*dit)--;
        }
        //如果双向队列的第一个元素就是要删除的那个，将它出队
        if (d.front() == 0)
        {
            d.pop_front();
        }
    }
};
int main()
{
    Solution solution;
    solution.push_back(1);
    cout << solution.max() << " ";
    solution.push_back(2);
    cout << solution.max() << " ";
    solution.push_back(3);
    cout << solution.max() << " ";
    solution.push_back(2);
    cout << solution.max() << " ";
    solution.pop_front();
    cout << solution.max() << " ";
    solution.pop_front();
    cout << solution.max() << " ";
    return 0;
}