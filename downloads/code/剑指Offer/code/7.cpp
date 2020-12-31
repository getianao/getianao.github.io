#include <iostream>
#include <vector>
using namespace std;

/*
重建二叉树：
给出二叉树的前序和中序序列，构建二叉树

思路：
前序序列的第一个元素是根节点，通过这个根节点在中序划分出左右两个子树。重复这个过程，直到构建整个二叉树。

测试用例：https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if (pre.size() == 0)
        {
            return NULL;
        }
        int rootVal = pre[0];
        TreeNode *root = new TreeNode(rootVal); //根节点
        int vinFlag = 0;                        //为0时属于左子树，为1时属于右子树
        int preFlag = 0;                        //小于等于leftVin属于左子树，大于属于右子树
        vector<int> leftVin, rightVin;          //左右子树中序序列
        vector<int> leftPre, rightPre;          //左右子树前序序列
        if (pre.size() == 1)
        {
            return root;
        }
        for (int i = 0; i < vin.size(); i++)
        {
            if (vin[i] == rootVal)
            {
                vinFlag = 1;
                continue;
            }
            if (vinFlag == 0)
            {
                leftVin.push_back(vin[i]);
            }
            else
            {
                rightVin.push_back(vin[i]);
            }
        }
        for (int i = 1; i < pre.size(); i++) //跳过根节点
        {
            if (preFlag < leftVin.size())
            {

                leftPre.push_back(pre[i]);
            }
            else
            {
                rightPre.push_back(pre[i]);
            }
            preFlag++;
        }
        if (leftPre.size() != leftVin.size() || rightPre.size() != rightVin.size())
        {
            cout << "wrong!" << endl;
        }
        root->left = reConstructBinaryTree(leftPre, leftVin);
        root->right = reConstructBinaryTree(rightPre, rightVin);
        return root;
    }
};

void getPostOrder(TreeNode *root, vector<int> *pos)
{
    if (root->left != NULL)
    {
        getPostOrder(root->left, pos);
    }
    if (root->right != NULL)
    {
        getPostOrder(root->right, pos);
    }
    pos->push_back(root->val);
};
int main()
{
    vector<int> pre;
    int preArray[] = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> vin;
    int vinArray[] = {4, 7, 2, 1, 5, 3, 8, 6};
    for (int i = 0; i < 8; i++)
    {
        pre.push_back(preArray[i]);
        vin.push_back(vinArray[i]);
    }
    Solution test;
    TreeNode *root = test.reConstructBinaryTree(pre, vin);
    vector<int> *pos = new vector<int>;
    getPostOrder(root, pos);
    cout<<"post order: ";
    for (vector<int>::iterator it = pos->begin(); it != pos->end(); it++)
    {
        cout << *it << " "; //vector指针需要使用迭代器，不能直接访问元素
    }
    return 0;
}
