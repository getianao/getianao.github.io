#include <iostream>
using namespace std;

/*
在O(1)时间内删除链表节点:
给定的是单向链表头指针和要删除的节点指针。
这里需要解释的是，需要考虑给出的节点是不是一定存在于链表中，不是的话则需要首先查找，这个过程一定需要O(n)；所以下面的讨论都是一定存在的情况。

思路一：遍历，这种方法可以安全的删除节点，但是需要O(1)。

思路二：要删除一个节点，需要将待删除节点的前一个节点的next指针指向待删除结点指向的下一个结点，但是一般方法只能通过遍历得到前一个节点；要得到O(1)，可以不改变前一个节点的指针，而改变指针指向节点。将待删除的节点的数据覆盖成它的下一个节点，再将它的next指针指向待删除结点的下下个结点。

*/
struct ListNode
{
    int m_nValue;
    ListNode *m_pNext = NULL;
};

class Solution
{
public:
    void deleteNode(ListNode *pListHead, ListNode *pToBeDeleted)
    {
        //链表中只有一个节点
        if (pListHead == pToBeDeleted)
        {
            pListHead = NULL;
            return;
        }
        //删除的是尾节点,必须遍历
        if (pToBeDeleted->m_pNext == NULL)
        {
            ListNode *ptr;
            ptr = pListHead;
            while (true)
            {
                if (ptr->m_pNext == pToBeDeleted)
                {
                    ptr->m_pNext = NULL;
                    return;
                }
                else
                {
                    ptr = ptr->m_pNext;
                }
            }
        }

        //一般情况
        pToBeDeleted->m_nValue = pToBeDeleted->m_pNext->m_nValue;
        pToBeDeleted->m_pNext = pToBeDeleted->m_pNext->m_pNext;
    }
};
int main()
{
    ListNode *pListHead;
    pListHead = new ListNode;
    ListNode *ptr;
    ptr = pListHead;
    for (int i = 0; i < 10; i++)
    {
        ptr->m_nValue = i;
        if (i != 9)
        {
            ptr->m_pNext = new ListNode;
            ptr = ptr->m_pNext;
        }
    }

    Solution solution;
    solution.deleteNode(pListHead, pListHead->m_pNext);

    while (pListHead != NULL)
    {
        cout << pListHead->m_nValue << " ";
        pListHead = pListHead->m_pNext;
    }
    return 0;
}