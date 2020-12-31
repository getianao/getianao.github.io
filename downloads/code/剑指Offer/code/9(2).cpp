#include <iostream>
#include <queue>
using namespace std;
/*
用两个队列实现一个栈

思路：
入栈；向非空队列中入队，如果两个队列皆为空，则任意队列入队。
出栈：对于一个非空队列，将除了最后一个元素以外的所有元素依次出队，并在另一个队列入队。最后一个元素为出栈元素。

vscode的code runner运行时1234，应该是3241，但terminal正常
*/

class Solution
{
public:
    void push(int node)
    {
        if (!queue1.empty())
        {
            queue1.push(node);
        }
        else
        {
            queue2.push(node);
        }
    }

    int pop()
    {
        if (!queue1.empty())
        {
            while (queue1.size() > 1)
            {
                queue2.push(queue1.front());
                queue1.pop();
            }
            int temp = queue1.front();
            queue1.pop();
            return temp;
        }
        if (!queue2.empty())
        {
            while (queue2.size() > 1)
            {
                queue1.push(queue2.front());
                queue2.pop();
            }
            int temp = queue2.front();
            queue2.pop();
            return temp;
        }
    }

private:
    queue<int> queue1;
    queue<int> queue2;
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