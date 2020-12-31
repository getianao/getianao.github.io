#include <iostream>
using namespace std;
/*
两个链表的第一个公共节点:
输入两个单向链表，找出它们的公共节点（一处）。

思路一：遍历第一支链表的所有节点，在第二支链表中查找是否含有第一支链表中的这个节点。时间复杂度是O(mn)。

思路二：如果它们存在公共节点，必然是两支链表交汇再同一点上，它们共用了一条链尾。分别遍历每一条链表的节点，将它们的节点分别放入栈中，在同时出栈比较，最后一个相同的节点即为公共节点。空间和时间复杂度均是O(m+n)。

思路三：我们不能像思路二从头开始分别比较直到节点相同，是因为两条链表可能不一样长，但是如果先得到两条链表的长度，让长的链表先前进几个节点，变为一样长，再同时比较就可以了。时间复杂度是O(m+n)。

测试用例：https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=11189&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
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
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == NULL || pHead2 == NULL)
        {
            return NULL;
        }
        int length1 = getLength(pHead1);
        int length2 = getLength(pHead2);
        while (length1 > length2)
        {
            pHead1 = pHead1->next;
            length1--;
        }
        while (length1 < length2)
        {
            pHead2 = pHead2->next;
            length2--;
        }
        for (int i = 0; i < length1; i++)
        {
            if (pHead1 == pHead2)
            {
                return pHead1;
            }
            else
            {
                pHead1 = pHead1->next;
                pHead2 = pHead2->next;
            }
        }
        return NULL;
    }
    int getLength(ListNode *pHead)
    {
        int length = 0;
        while (pHead != NULL)
        {
            length++;
            pHead = pHead->next;
        }
        return length;
    }
};
int main()
{
    Solution solution;
    ListNode *pHead1 = new ListNode(1);
    pHead1->next = new ListNode(2);
    pHead1->next->next = new ListNode(3);
    pHead1->next->next->next = new ListNode(6);
    pHead1->next->next->next->next = new ListNode(7);
    ListNode *pHead2 = new ListNode(4);
    pHead2->next = new ListNode(6);
    pHead2->next->next = pHead1->next->next->next;
    cout << (solution.FindFirstCommonNode(pHead1, pHead2))->val << endl;
    return 0;
}