#include <iostream>
using namespace std;
/*
链表中的倒数第k个节点：
链表是单向链表

思路一：将整个链表遍历两次，第一次得到整个链表的节点个数，第二次从前向后数到倒数的节点

思路二：当一个链表表里不能解决问题的时候，可以使用两个指针，一个走的慢一些，一个走的快一些。
使用两个指针，两个指针之间的距离保持为k，这样当后一个指针到达最后一个节点时，前一个指针指向倒数第k个节点。
注意代码的鲁棒性：链表指针不能为NULL，k必须大于0且小于链表长度。


测试用例：https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&tqId=11167&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        if (pListHead == NULL || k <= 0)
        {
            return NULL;
        }
        ListNode *p1, *p2;
        p1 = pListHead;
        p2 = pListHead;
        for (int i = 0; i < k - 1; i++)
        {
            p1 = p1->next;
            if (p1 == NULL)
            {
                return NULL;
            }
        }
        while (p1->next != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
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
    Solution Solution;
    cout << Solution.FindKthToTail(pListHead, 3)->val << endl;
    ;
}