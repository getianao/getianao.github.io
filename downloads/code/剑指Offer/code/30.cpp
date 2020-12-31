#include <iostream>
#include <stack>
using namespace std;
/*
包含min函数的栈：
可以得到栈中的最小值。

思路：用一个变量存储最小值，新元素压栈容易处理，但是出栈时需要知道次小元素是多少。所以用以个辅助栈存储前i个元素的最小值，出栈时也对辅助栈做出栈操作。

测试用例：https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

*/
class Solution
{
public:
    stack<int> s;
    stack<int> f;
    void push(int value)
    {
        s.push(value);
        if (s.size() == 1)
        {
            f.push(value);
        }
        else
        {
            if (f.top() > value)
            {
                f.push(value);
            }
            else
            {
                f.push(f.top());
            }
        }
    }
    void pop()
    {
        if (s.size() > 0)
        {
            s.pop();
            f.pop();
        }
    }
    int top()
    {
        return s.top();
    }
    int min()
    {
        return f.top();
    }
};

int main()
{
    Solution solution;
    solution.push(3);
    cout << solution.min() << endl;
    solution.push(4);
    cout << solution.min() << endl;
    solution.push(2);
    cout << solution.min() << endl;
    return 0;
}