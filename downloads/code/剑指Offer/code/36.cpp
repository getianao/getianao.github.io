#include <iostream>
using namespace std;
/*
二叉搜索树与双向链表：
将二叉搜索树转换成一个排序的链表。

思路：递归的思想，对于每一个树，它的左右子树递归得到排序的链表，然后将左边链表最大元素和根节点和右边链表最小元素连接起来。如果是叶子节点，就返回它。自己

测试用例：nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&tqId=11179&tPage=2&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};
class Solution
{
public:
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        TreeNode *leftList = NULL;
        TreeNode *rightList = NULL;
        if (pRootOfTree == NULL)
        {
            return NULL;
        }
        else
        {
            if (pRootOfTree->left != NULL)
            {
                leftList = Convert(pRootOfTree->left);
                //此时左子树已经是排序的链表了，且都比根节点小
                TreeNode *ptr = leftList;
                while (ptr->right != NULL) //找到最大的元素
                {
                    ptr = ptr->right;
                }
                ptr->right = pRootOfTree;
                pRootOfTree->left = ptr;
            }
            else
            {
                pRootOfTree->left = NULL;
            }
            if (pRootOfTree->right != NULL)
            {
                rightList = Convert(pRootOfTree->right);
                //此时右子树已经是排序的链表了，且都比根节点大
                TreeNode *ptr = rightList;
                ptr->left = pRootOfTree;
                pRootOfTree->right = ptr;
            }
            else
            {
                pRootOfTree->right = NULL;
            }
        }
        if (leftList != NULL)
        {
            return leftList;
        }
        else
        {
            return pRootOfTree;
        }
    }
};
int main()
{
    TreeNode *pRoot1 = new TreeNode(10);
    pRoot1->left = new TreeNode(6);
    pRoot1->right = new TreeNode(14);
    pRoot1->left->left = new TreeNode(4);
    pRoot1->left->right = new TreeNode(8);
    pRoot1->right->left = new TreeNode(12);
    pRoot1->right->right = new TreeNode(16);
    Solution solution;
    TreeNode *list = solution.Convert(pRoot1);
    return 0;
}