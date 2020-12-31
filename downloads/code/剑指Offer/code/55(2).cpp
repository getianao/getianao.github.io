
#include <iostream>
using namespace std;
/*
平衡二叉树：
判断是否为平衡二叉树，即任意节点的左右子树深度相差不超过1。

思路一：对于每个节点都去计算它的子树的深度，然后判断。
这样会在成很多重复遍历，子树的深度也会被计算多次。

思路二：将遍历的过程中加上判断，从下到上，先判断子树，再判断根节点。

测试用例：https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&tqId=11192&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
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
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        int depth = 0;
        return isBalance(pRoot, depth);
    }

    bool isBalance(TreeNode *pRoot, int &depth)
    {
        int left = 0, right = 0;
        if (pRoot == NULL)
        {
            return true;
        }
        //叶子节点，平衡，深度为1
        if (pRoot->left == NULL && pRoot->right == NULL)
        {
            depth = 1;
            return true;
        }

        //判断左右子树是否平衡，并计算深度
        if (pRoot->right != NULL)
        {
            if (isBalance(pRoot->right, depth) == true)
            {
                right = depth;
            }
            else
            {
                return false;
            }
        }
        if (pRoot->left != NULL)
        {
            if (isBalance(pRoot->left, depth) == true)
            {
                left = depth;
            }
            else
            {
                return false;
            }
        }
        if (left - right > 1 || right - left > 1)
        {
            return false;
        }
        else
        {
            depth = (left > right) ? left + 1 : right + 1;
            return true;
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
    if (solution.IsBalanced_Solution(pRoot1) == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}