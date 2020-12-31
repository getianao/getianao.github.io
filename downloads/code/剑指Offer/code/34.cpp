#include <iostream>
#include <vector>
using namespace std;
/*
二叉树中和为某一值的路径：
二叉树中的路径是从根节点到叶子节点所经过的所有节点。
(注意: 在返回值的list中，数组长度大的数组靠前)

思路：遍历，使用了栈以便在遍历完左子树之后可以继续遍历右子树；栈中不需要存储节点，只需要存储节点的值，因为在递归中是先写的访问左右子树，再弹出栈。

测试用例：https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=11177&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
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
    vector<vector<int> > FindPath(TreeNode *root, int expectNumber)
    {
        vector<vector<int> > *output = new vector<vector<int> >;
        vector<int> *path = new vector<int>;
        if (root == NULL)
        {
            return *output;
        }
        FindPathInTree(root, expectNumber, 0, path, output);
        sortOutput(output);
        return *output;
    }

    void FindPathInTree(TreeNode *root, int expectNumber, int currentNumber, vector<int> *path, vector<vector<int> > *output)
    {
        path->push_back(root->val);
        currentNumber = currentNumber + root->val;
        if (root->left == NULL && root->right == NULL)
        {
            //当前节点为叶子节点
            if (currentNumber == expectNumber)
            {
                //符合条件的路径,则添加至数组
                output->push_back(*path);
            }
        }
        else
        {
            //不是叶子节点，继续遍历它的子节点
            if (root->left != NULL)
            {
                FindPathInTree(root->left, expectNumber, currentNumber, path, output);
            }
            if (root->right != NULL)
            {
                FindPathInTree(root->right, expectNumber, currentNumber, path, output);
            }
        }
        path->pop_back();
    }

    //使长的路径排在前面
    void sortOutput(vector<vector<int> > *output)
    {
        if (output->size() <= 1)
        {
            return;
        }
        for (int i = 0; i < output->size() - 1; i++)
        {
            for (int j = i; j < output->size() - 1; j++)
            {
                if ((*output)[j].size() < (*output)[j + 1].size())
                {
                    vector<int> temp = (*output)[j];
                    (*output)[j] = (*output)[j + 1];
                    (*output)[j + 1] = temp;
                }
            }
        }
    }
};
int main()
{
    TreeNode *pRoot1 = new TreeNode(10);
    pRoot1->left = new TreeNode(12);
    pRoot1->right = new TreeNode(5);
    pRoot1->right->left = new TreeNode(4);
    pRoot1->right->right = new TreeNode(7);
    Solution solution;
    vector<vector<int> > output;
    output = solution.FindPath(pRoot1, 22);
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