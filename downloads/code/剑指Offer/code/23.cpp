#include <iostream>
using namespace std;
/*
链表中环的入口节点：
首先需要判断链表中是否有环，然后找到环的入口节点。

思路一：使用快慢指针的方法；首先判断是否有环，使慢指针一次移动一个节点，快指针一次移动两个节点，如果没有环，快指针首先到达链表末尾，如果有环，慢指针和快指针会在环中的某个节点相遇。
然后找入口节点，从刚刚找到的节点开始，首先计算出环中的节点个数，然后是从链表头节点开始设置两个指针，这两个指针之间的距离为环的长度，然后两个指针同时后移，最终两个指针将在入口节点处相遇。

测试用例：https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=11208&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        ListNode *ptr = hasLoop(pHead);
        int num;         //环中节点数量
        if (ptr == NULL) //无环
        {
            return NULL;
        }
        else
        {
            num = nodeNumOfLoop(ptr);
        }
        ListNode *p1, *p2;
        p1 = pHead;
        p2 = p1;
        for (int i = 0; i < num; i++)
        {
            p2 = p2->next;
        }
        while (p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }

    //是否有环
    ListNode *hasLoop(ListNode *pHead)
    {
        ListNode *p1, *p2;
        p1 = pHead;
        if (p1 == NULL)
        {
            return NULL;
        }
        p2 = pHead->next;
        if (p2 == NULL)
        {
            return NULL;
        }
        while (p1 != NULL || p2 != NULL)
        {
            if (p1 == p2)
            {
                return p1;
            }
            else
            {
                p1 = p1->next;
                p2 = p2->next;
                if (p2 == NULL)
                {
                    return NULL;
                }
                else
                {
                    p2 = p2->next;
                }
            }
        }
        return NULL;
    }
    //环中的节点数量
    int nodeNumOfLoop(ListNode *node)
    {
        int num = 1;
        ListNode *ptr = node->next;
        while (ptr != node)
        {
            ptr = ptr->next;
            num++;
        }
        return num;
    }
};

int main()
{
    ListNode *pListHead, *ptr, *entry;
    pListHead = new ListNode(1);
    ptr = pListHead;
    for (int i = 2; i < 7; i++)
    {
        ptr->next = new ListNode(i);
        ptr = ptr->next;
        if (i == 3)
        {
            entry = ptr;
        }
    }
    ptr->next = entry;
    Solution solution;
    cout << solution.EntryNodeOfLoop(pListHead)->val << endl;
    return 0;
}