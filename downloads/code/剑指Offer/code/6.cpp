#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
从尾到头打印链表：
通常打印是个只读操作，假设面试官要求改变原有的链表结构。

思路一：栈
顺序的反转让我们想到用栈来实现

思路二：递归
递归的本质就是一个栈结构，使用函数的递归先递归输出后面的一个节点，再输出自身。这种方法再代码上更简洁，但递归的函数层数太深可能会导致函数调用栈溢出，稳定性不如用循环实现的栈。

测试用例：https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Solution
{
public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> listVector;
        stack<int> listStack;
        ListNode *ptr = head;
        while (true)
        {
            if (ptr == NULL)
            {
                break;
            }
            else
            {
                listStack.push(ptr->val);
                ptr = ptr->next;
            }
        }
        while (!listStack.empty())
        {
            listVector.push_back(listStack.top());
            listStack.pop();
        }
        return listVector;
    }
};

int main()
{
    ListNode *head = NULL;
    ListNode *end = NULL;
    for (int i = 0; i < 5; i++)
    {
        ListNode *listPtr = new ListNode(i);
        if (head == NULL)
        {
            head = listPtr;
            end = head;
        }
        else
        {
            end->next = listPtr;
            end = end->next;
        }
    }

    vector<int> reverseVector;
    Solution test;
    reverseVector = test.printListFromTailToHead(head);
    for (int i = 0; i < reverseVector.size(); i++)
    {
        cout<<reverseVector[i]<<" ";
    }
    return 0;
}