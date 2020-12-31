#include <iostream>
using namespace std;
/*
反转链表：

思路一：反转一个单向链表，就是要改变每一个节点的next指针指向前一个，所以这个操作要注意要保存后一个节点防止断链，要保存前一个节点因为单向链表不能往前看。
鲁棒性：① 输入指针为NULL。
②输入链表只有一个节点。

思路二：递归的实现方法。

测试用例：
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
    ListNode *ReverseList(ListNode *pHead)
    {
        ListNode *pre, *ptr, *rear;
        pre = NULL;
        ptr = pHead;
        while (ptr != NULL)
        {
            if (ptr->next == NULL) //新的头节点
            {
                ptr->next = pre;
                break;
            }
            //对原来的头节点也适用
            rear = ptr->next; //保存后一个节点啊
            ptr->next = pre;  //断链
            pre = ptr;        //pre变为原来的ptr
            ptr = rear;       //ptr指向下一个
        }
        return ptr;
    }
};

int main()
{
    ListNode *pListHead, *ptr;
    pListHead = new ListNode(1);
    ptr = pListHead;
    for (int i = 2; i < 10; i++)
    {
        ptr->next = new ListNode(i);
        ptr = ptr->next;
    }
    Solution solution;
    pListHead = solution.ReverseList(pListHead);
    while (pListHead != NULL)
    {
        cout << pListHead->val << " ";
        pListHead=pListHead->next;
    }
    return 0;
}