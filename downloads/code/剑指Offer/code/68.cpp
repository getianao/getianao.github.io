#include <iostream>
#include <stack>
using namespace std;
/*
树中两个节点的最低公共祖先：
树是普通的二叉树，没有指向父节点的指针。

思路一：递归，从根节点开始判断，判断根节点的左右两个子树书否包含这两个节点，如果两个都包含，则这个节点就是最低公共祖先，如果两个节点都包含在左右一颗子树上，则在这颗子树上继续寻找。

思路二：使用辅助空间，先使用两个栈找到从根节点到两个节点的路径，然后再从队列中从后往前找第一个出现的公共祖先。
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
    TreeNode *getNode(TreeNode *a, TreeNode *b, TreeNode *root)
    {
        stack<TreeNode *> treea;
        stack<TreeNode *> treeb;
        findWay(root, a, treea);
        findWay(root, b, treeb);
        int aaa = treea.size();
        while (treea.size() > treeb.size())
        {
            treea.pop();
        }
        while (treea.size() < treeb.size())
        {
            treeb.pop();
        }
        while (treea.top() != treeb.top())
        {
            treea.pop();
            treeb.pop();
        }
        return treea.top();
    }

    //寻找根节点到某节点的路径
    bool findWay(TreeNode *root, TreeNode *a, stack<TreeNode *> &q)
    {
        if (root->val == a->val)
        {
            return true;
        }
        else
        {
            q.push(root);
            if (root->left != NULL)
            {
                if (findWay(root->left, a, q) == true)
                {
                    //❗需要提前终止
                    return true;
                }
            }
            if (root->right != NULL)
            {
                if (findWay(root->right, a, q) == true)
                {
                    return true;
                }
            }
            q.pop();
        }
        return false;
    }
};
int main()
{
    TreeNode *pRoot1 = new TreeNode(5);
    pRoot1->left = new TreeNode(3);
    pRoot1->right = new TreeNode(7);
    pRoot1->left->left = new TreeNode(2); //b
    pRoot1->left->right = new TreeNode(4);
    pRoot1->left->right->left = new TreeNode(1); //a
    pRoot1->right->left = new TreeNode(6);
    pRoot1->right->right = new TreeNode(8);
    Solution solution;
    TreeNode *node = solution.getNode(pRoot1->left->right->left, pRoot1->left->left, pRoot1);
    cout << node->val << endl;
}