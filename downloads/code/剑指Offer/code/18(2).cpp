#include <iostream>
using namespace std;
/*
删除链表中重复的节点：
链表是有序（从小到大），重复的节点不保留。

思路：由于重复的节点都要被删除，所以必须保留重复节点的上个数值的节点。所以必须要有一个指针指向上一个数值的节点，还有一个指针指向检查是否重复的节点。
书中指出用一个二重指针指向链表头，因为链表的第一个节点是可能被删除的，这样链表的头指针就不会发生变化。牛客中仍然使用一重的指针，下面代码也是。

测试用例：https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&tqId=11209&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Solution
{
public:
    ListNode *deleteDuplication(ListNode *pHead)
    {
        ListNode *pre = NULL;
        ListNode *ptr;
        if (pHead == NULL || pHead->next == NULL)
        {
            //链表为空或只有一个节点
            return pHead;
        }

        while (pre == NULL) //首先检查第一个节点是否是重复的
        {
            if (pHead->val != pHead->next->val)
            {
                //没有重复，跳出
                pre = pHead;
                ptr = pHead->next;
                break;
            }
            else
            { //有重复
                while (pHead->val == pHead->next->val)
                {
                    pHead = pHead->next;
                    if (pHead->next == NULL)
                    {
                        //链表中只有两种元素的情况
                        pHead = NULL;
                        return pHead;
                    }
                }
                pHead = pHead->next;
                if (pHead->next == NULL)
                {
                    return pHead;
                }
                if ((pHead->next != NULL) && (pHead->val != pHead->next->val))
                {
                    ptr = pHead;
                    break;
                }
            }
        }

        while (ptr->next != NULL)
        {
            if (ptr->val != ptr->next->val) //ptr和下一个不重复
            {
                pre = ptr;
                ptr = ptr->next;
            }
            else //ptr和下一个重复
            {
                while (ptr->next != NULL && ptr->next->val == ptr->val)
                {
                    ptr = ptr->next;
                }
                //此时ptr->next是NULL或不相同
                if (ptr->next == NULL)
                {
                    pre->next = NULL;
                    return pHead;
                    ;
                }
                pre->next = ptr->next;
                ptr = ptr->next;
                //pre不变
            }
        }
        return pHead;
    }
};
int main()
{

    ListNode *pListHead;
    pListHead = new ListNode(0);
    ListNode *ptr;
    ptr = pListHead;
    for (int i = 0; i < 3; i++)
    {
        ptr->next = new ListNode(i);
        if (i == 1)
        {
            ptr = ptr->next;
            ptr->next = new ListNode(1);
            ptr = ptr->next;
            continue;
        }
        if (i == 2)
        {
            ptr = ptr->next;
            ptr->next = new ListNode(2);
            ptr = ptr->next;
            continue;
        }
        if (i == 8)
        {
            ptr = ptr->next;
            ptr->next = new ListNode(8);
            ptr = ptr->next;
            ptr->next = new ListNode(8);
            ptr = ptr->next;
            continue;
        }
        if (i != 9)
        {
            ptr = ptr->next;
        }
        else
        {
            ptr = ptr->next;
            ptr->next = new ListNode(9);
        }
    }

    Solution solution;
    ListNode *p = pListHead;
    while (p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    pListHead = solution.deleteDuplication(pListHead);
    while (pListHead != NULL)
    {
        cout << pListHead->val << " ";
        pListHead = pListHead->next;
    }
    return 0;
}