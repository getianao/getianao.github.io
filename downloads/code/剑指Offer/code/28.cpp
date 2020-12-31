#include <iostream>
using namespace std;
/*
对称的二叉树：

思路：考虑二叉树的遍历，例如使用先序遍历得到先序遍历的序列，在定义一个对称的先序遍历（根节点->右节点->左节点），如果这两个序列相同，则为对称的二叉树。
对于节点都相同的二叉树，两个序列可能相同，所以子节点中有一个为空时需要用NULL占位。

测试用例：https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb?tpId=13&tqId=11211&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
    bool isSymmetrical(TreeNode *pRoot)
    {
        int result = false;
        if (pRoot != NULL)
        {
            result = preOrder(pRoot, pRoot);
        }
        else
        {
            result = true;
        }
        return result;
    }

    bool preOrder(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        bool result = false;
        if (pRoot1 == NULL && pRoot2 == NULL)
        {
            return true;
        }
        if ((pRoot1 != NULL && pRoot2 != NULL) && (pRoot1->val == pRoot2->val))
        {
            result = preOrder(pRoot1->left, pRoot2->right);
            if (result == true)
            {
                result = preOrder(pRoot1->right, pRoot2->left);
            }
            return result;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    TreeNode *pRoot1 = new TreeNode(8);
    pRoot1->left = new TreeNode(6);
    pRoot1->right = new TreeNode(6);
    pRoot1->left->left = new TreeNode(5);
    pRoot1->left->right = new TreeNode(7);
    pRoot1->right->left = new TreeNode(8);
    pRoot1->right->right = new TreeNode(5);
    Solution solution;
    if (solution.isSymmetrical(pRoot1) == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}