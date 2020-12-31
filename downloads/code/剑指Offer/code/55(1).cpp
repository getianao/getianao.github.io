#include <iostream>
using namespace std;
/*
二叉树的深度：
深度是从根到叶子节点的醉成路径长度。

思路：通过递归，返回左右子树的较大值。
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
    int TreeDepth(TreeNode *pRoot)
    {
        int left = 0, right = 0;
        if (pRoot == NULL)
        {
            return 0;
        }
        if (pRoot->left == NULL && pRoot->right == NULL)
            return 1;
        if (pRoot->right != NULL)
        {
            right = TreeDepth(pRoot->right) + 1;
        }
        if (pRoot->left != NULL)
        {
            left = TreeDepth(pRoot->left) + 1;
        }
        if (left > right)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
};
int main()
{
    TreeNode *pRoot1 = new TreeNode(5);
    pRoot1->left = new TreeNode(3);
    pRoot1->right = new TreeNode(7);
    pRoot1->left->left = new TreeNode(2);
    pRoot1->left->right = new TreeNode(4);
    pRoot1->left->right->left = new TreeNode(4);
    pRoot1->right->left = new TreeNode(6);
    pRoot1->right->right = new TreeNode(8);
    Solution solution;
    cout << solution.TreeDepth(pRoot1) << endl;
    return 0;
}