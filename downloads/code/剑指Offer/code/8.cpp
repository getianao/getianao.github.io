#include <iostream>
using namespace std;
/*
二叉树的下一个节点：
给出一个节点，找出这个节点在中序遍历中的下一个节点。树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

思路：
从树的结构上进行分析，并需要进行分类讨论：
①如果这个节点有右子树，那么下一个节点就为它的右子树的最左节点。
②如果这个节点没有右子树：
Ⅰ：如果它是父节点的左节点，那么下一个节点就为父节点。
Ⅱ：如果它是父节点的右节点：需要一直向上寻找，直到存在一个节点是它的父节点的左节点，那么它的父节点就是下一个节点。

测试用例：
*/

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next; //指向父节点的指针
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL)
    {
    }
};

class Solution
{
public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        if (pNode->right != NULL) //右子树存在
        {
            TreeLinkNode *ptr = pNode->right;
            while (ptr->left != NULL)
            {
                ptr = ptr->left;
            }
            return ptr;
        }
        else //右子树不存在
        {
            if (pNode->next == NULL)
            {
                return NULL;
            }
            if (pNode == pNode->next->left) //是父节点的左子树
            {
                return pNode->next;
            }
            else if (pNode == pNode->next->right) //是父节点的右子树
            {
                TreeLinkNode *ptr = pNode->next;
                while (ptr->next != NULL) //根节点没有父节点
                {
                    if (ptr == ptr->next->left)
                    {
                        return ptr->next;
                    }
                    else
                    {
                        ptr = ptr->next;
                    }
                }
                return NULL;
            }
        }
        return NULL;
    }
};

int main()
{
    TreeLinkNode *root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);
    root->right->left = new TreeLinkNode(6);
    root->right->right = new TreeLinkNode(7);
    root->left->right->left = new TreeLinkNode(8);
    root->left->right->right = new TreeLinkNode(9);
    root->left->next = root;
    root->right->next = root;
    root->left->left->next = root->left;
    root->left->right->next = root->left;
    root->right->left->next = root->right;
    root->right->right->next = root->right;
    root->left->right->left->next = root->left->right;
    root->left->right->right->next = root->left->right;
    Solution test;
    cout << "the next node of 9 is " << test.GetNext(root->left->right->right)->val << endl;
    return 0;
}