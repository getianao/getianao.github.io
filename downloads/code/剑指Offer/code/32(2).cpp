#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
分行从上到下打印二叉树：
处于同层的节点打印在同一行

思路：维护两个变量存储本行还没打印节点的数量和下一行要打印的节点的数量。在出队和入队时对着两个变量进行修改。本行未打印节点数量为0时换行并将它赋值为下一行的数量。

测试用例：https://www.nowcoder.com/practice/445c44d982d04483b04a54f298796288?tpId=13&tqId=11213&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
    vector<vector<int> > Print(TreeNode *pRoot)
    {
        vector<vector<int> > output;
        vector<int> array;
        int remain = 0, next = 0; //当前行还没打印的节点，下一行需要打印的节点
        queue<TreeNode *> q;
        if (pRoot == NULL)
        {
            return output;
        }
        q.push(pRoot);
        remain = 1;
        TreeNode *ptr;
        while (q.size() != 0)
        {
            if (remain == 0) //当前行节点打印完了
            {
                remain = next;
                next = 0;
                output.push_back(array);
                array.clear();
            }
            TreeNode *temp = q.front();
            q.pop();
            array.push_back(temp->val);
            remain--;
            if (temp->left != NULL)
            {
                q.push(temp->left);
                next++;
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
                next++;
            }
        }
        output.push_back(array);
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
    vector<vector<int> > output = solution.Print(pRoot1);
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}