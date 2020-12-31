#include <iostream>
using namespace std;
/*
二叉树的镜像：

测试用例：https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&tqId=11171&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
    void Mirror(TreeNode *pRoot)
    {
        if (pRoot == NULL)
        {
            return;
        }
        else
        {
            TreeNode *temp;
            temp = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = temp;
        }
        if (pRoot->left != NULL)
        {
            Mirror(pRoot->left);
        }
        if (pRoot->right != NULL)
        {
            Mirror(pRoot->right);
        }
    }
};

void printTree(TreeNode *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        cout << tree->val <<" ";
        printTree(tree->left);
        printTree(tree->right);
    }
}

int main()
{
    TreeNode *pRoot1 = new TreeNode(8);
    pRoot1->left = new TreeNode(6);
    pRoot1->right = new TreeNode(10);
    pRoot1->left->left = new TreeNode(5);
    pRoot1->left->right = new TreeNode(7);
    pRoot1->right->left = new TreeNode(9);
    pRoot1->right->right = new TreeNode(11);
    Solution solution;
    printTree(pRoot1);
    cout << endl;
    solution.Mirror(pRoot1);
    printTree(pRoot1);
    cout << endl;
    return 0;
}