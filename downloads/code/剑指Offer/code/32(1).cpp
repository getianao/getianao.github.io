#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
从上到下打印二叉树：
同层节点从左到右。

思路：借助一个队列，首先将根节点入队，每个节点出队时将它的所有子节点按照从左到右的方法入队，直到所有元素出队。
广度优先遍历用队列。

测试用例：https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?tpId=13&tqId=11175&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        vector<int> output;
        queue<TreeNode *> q;
        if(root==NULL)
        {
            return output;
        }
        q.push(root);
        TreeNode *ptr;
        while (q.size() != 0)
        {
            TreeNode *temp = q.front();
            q.pop();
            output.push_back(temp->val);
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        return output;
    }
};
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
    vector<int> array = solution.PrintFromTopToBottom(pRoot1);
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}