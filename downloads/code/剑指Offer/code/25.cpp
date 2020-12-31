#include <iostream>
using namespace std;
/*
合并两个排序的链表：

鲁棒性：注意两个链表指针为空的情况。

测试用例：https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == NULL && pHead2 == NULL)
        {
            return NULL;
        }
        if (pHead1 == NULL && pHead2 != NULL)
        {
            return pHead2;
        }
        if (pHead1 != NULL && pHead2 == NULL)
        {
            return pHead1;
        }
        ListNode *pHead = NULL,*ptr,*p1 = pHead1, *p2 = pHead2;
        while (true)
        {
            if (p1 == NULL)
            {
                ptr->next = p2;
                break;
            }
            if (p2 == NULL)
            {
                ptr->next = p1;
                break;
            }
            if (p1->val <= p2->val)
            {
                if (pHead == NULL)
                {
                    pHead = p1;
                    ptr=pHead;
                    p1 = p1->next;
                }
                else
                {
                    ptr->next = p1;
                    ptr = ptr->next;
                    p1 = p1->next;
                }
            }
            else
            {
                if (pHead == NULL)
                {
                    pHead = p2;
                    ptr=pHead;
                    p2 = p2->next;
                }
                else
                {
                    ptr->next = p2;
                    ptr = ptr->next;
                    p2 = p2->next;
                }
            }
        }
        return pHead;
    }
};
int main()
{
    ListNode *pListHead1, *ptr1;
    pListHead1 = new ListNode(1);
    ptr1 = pListHead1;
    ptr1->next = new ListNode(3);
    ptr1 = ptr1->next;
    ptr1->next = new ListNode(5);
    ptr1 = ptr1->next;
    ptr1->next = new ListNode(7);
    ptr1 = ptr1->next;
    ListNode *pListHead2, *ptr2;
    pListHead2 = new ListNode(2);
    ptr2 = pListHead2;
    ptr2->next = new ListNode(3);
    ptr2 = ptr2->next;
    ptr2->next = new ListNode(6);
    ptr2 = ptr2->next;
    ptr2->next = new ListNode(8);
    ptr2 = ptr2->next;
    Solution solution;
    ListNode *ptr = solution.Merge(pListHead1, pListHead2);
    while (ptr != NULL)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    return 0;
}