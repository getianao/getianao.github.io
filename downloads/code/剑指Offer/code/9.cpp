#include <iostream>
#include <stack>
using namespace std;
/*
用两个栈实现队列

思路：
入队：入队时向 stack1 压栈
出队：出队时先由 stack2 出栈，如果 stack2 为空，则将 stack1 所有元素依次出栈并压入 stack2 ，在由stack2 出栈

测试用例：https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=13&tqId=11158&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution
{
public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                int temp = stack1.top();
                stack2.push(temp);
                stack1.pop();
            }
        }
        int temp2 = stack2.top();
        stack2.pop();
        return temp2;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
    Solution test;
    test.push(1);
    test.push(2);
    test.push(3);
    int out1 = test.pop();
    int out2 = test.pop(); //不要把 test.pop()写在cout中，因为cout优先级从右向左
    cout << out1 << " " << out2 << " ";
    test.push(4);
    int out3 = test.pop();
    int out4 = test.pop();
    cout << out3 << " " << out4 << " ";
    return 0;
}