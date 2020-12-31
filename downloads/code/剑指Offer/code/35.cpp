#include <iostream>
using namespace std;
/*
复杂链表的复制：
链表节点除了有一个指向下一个结点的指针，还有一个指向任意节点（也可以是空）的指针。

思路一：首先复制链表和next指针，然后复制random指针，由于不确定random指针位置，时间复杂度是O(n^2)

思路二：用空间换时间，再复制链表和next指针时，创建一个哈希表存储每一个节点间，在复制random指针时就可以用O(1)的时间找到节点。

思路三：首先在原链表的节点后复制同样的节点，复制节点的random指针指向原节点的random指针的下一个，然后再将链表拆分为两个链表。

测试用例：
*/

struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL)
    {
    }
};

class Solution
{
public:
    RandomListNode *Clone(RandomListNode *pHead)
    {
        if (pHead == NULL)
        {
            return NULL;
        }
        RandomListNode *ptr = pHead;
        //复制节点和next
        while (ptr != NULL)
        {
            RandomListNode *temp = new RandomListNode(ptr->label);
            temp->next = ptr->next;
            ptr->next = temp;
            ptr = temp->next;
        }
        //设置random
        ptr = pHead;
        while (ptr != NULL)
        {
            if (ptr->random != NULL) //注意Random为空的情况
            {
                ptr->next->random = ptr->random->next;
            }
            ptr = ptr->next->next;
        }
        //分裂列表
        int index = 0;
        RandomListNode *pNewHead = pHead->next;
        ptr = pNewHead;
        while (ptr->next != NULL)
        {
            ptr->next = ptr->next->next;
            ptr = ptr->next;
        }
        pHead->next = NULL; //判题程序不允许节点在输入参数中出现
        return pNewHead;
    }
};
int main()
{
    RandomListNode *ptr = new RandomListNode(1);
    ptr->next = new RandomListNode(2);
    ptr->next->next = new RandomListNode(3);
    ptr->next->next->next = new RandomListNode(4);
    ptr->next->next->next->next = new RandomListNode(5);
    ptr->random = ptr->next->next;
    ptr->next->random = ptr->next->next->next->next;
    ptr->next->next->next->random = ptr->next;
    Solution solution;
    RandomListNode *head = solution.Clone(ptr);
    return 0;
}