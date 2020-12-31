#include <iostream>
using namespace std;
/*
树的子结构：
判断树A是否是树B的子结构，规定空树不是任何一个树的子结构。

思路：树的查找和比较用的递归的思想，每次比较根节点，相同的话在去比较左子树和右子树。要注意空指针的情况。

测试用例：https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&tqId=11170&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        bool result = false;
        if (pRoot1 != NULL && pRoot2 != NULL)
        {
            if (pRoot1->val == pRoot2->val)
            {
                //根节点相同，则往下检查
                result = haveTree(pRoot1, pRoot2);
            }
            if (result == false)
            {
                //没有找到，则找左子树
                result = HasSubtree(pRoot1->left, pRoot2);
            }
            if (result == false)
            {
                //左子树也没有找到，则找右子树
                result = HasSubtree(pRoot1->right, pRoot2);
            }
        }
        return result;
    }
    bool haveTree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (pRoot2 != NULL && pRoot1 == NULL)
        {
            return false;
        }
        
        if (pRoot2 == NULL)
        {
            return true;
        }
        if (pRoot1->val == pRoot2->val)
        {
            return haveTree(pRoot1->left, pRoot2->left) && haveTree(pRoot1->right, pRoot2->right);
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
    pRoot1->left = new TreeNode(8);
    pRoot1->right = new TreeNode(7);
    pRoot1->left->left = new TreeNode(9);
    pRoot1->left->right = new TreeNode(2);
    pRoot1->left->right->left = new TreeNode(4);
    pRoot1->left->right->right = new TreeNode(4);
    TreeNode *pRoot2 = new TreeNode(8);
    pRoot2->left = new TreeNode(9);
    pRoot2->right = new TreeNode(2);
    Solution solution;
    int result = solution.HasSubtree(pRoot1, pRoot2);
    if (result == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}