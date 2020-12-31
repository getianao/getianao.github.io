#include <iostream>
#include <vector>
using namespace std;
/*
二叉搜索树的第k大节点:

思路：结合二叉搜索树的特点，通过中序遍历找第k个元素即为第k大节点。
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
    TreeNode *KthNode(TreeNode *pRoot, int k)
    {
        vector<TreeNode *> node;
        if (pRoot == NULL || k <= 0)
        {
            return NULL;
        }
        inOrderTraversal(pRoot, node);
        if (node.size() < k)
        {
            return NULL;
        }
        else
        {
            return node[k - 1];
        }
    }

    //中序遍历
    void inOrderTraversal(TreeNode *pRoot, vector<TreeNode *> &node)
    {
        if (pRoot->left != NULL)
        {
            inOrderTraversal(pRoot->left, node);
        }
        node.push_back(pRoot);
        if (pRoot->right != NULL)
        {
            inOrderTraversal(pRoot->right, node);
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
    pRoot1->right->left = new TreeNode(6);
    pRoot1->right->right = new TreeNode(8);
    Solution solution;
    cout << solution.KthNode(pRoot1, 3)->val << endl;
    return 0;
}