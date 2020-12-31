#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
之字形打印二叉树：
第一行从左至右打印，第二行从右至左打印，第三行从左至右打印。

思路：考虑到需要反向的输出，可以使用两个栈完成；第一行从左到右打印，将第一行的节点直接入栈（只有一个元素），第二行从右向左，将第一行的子节点从左向右入栈。第三行从左向右，第二行元素出栈时（反向，从右向左），将其子节点从右向左入栈（这样得到的就是从左向右）

测试用例：https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=13&tqId=11212&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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

        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        vector<int> array;
        vector<vector<int> > output;
        s1.push(pRoot);
        int remain = 1, next = 0;
        int binary = 0;
        if (pRoot == NULL)
        {
            return output;
        }
        while (true)
        {
            if (s1.size() == 0 && s2.size() == 0)
            {
                break;
            }
            if (binary % 2 == 0)
            {
                TreeNode *temp = s1.top();
                s1.pop();
                array.push_back(temp->val);
                remain--;
                //下一行是从右向左
                if (temp->left != NULL)
                {
                    s2.push(temp->left);
                    next++;
                }
                if (temp->right != NULL)
                {
                    s2.push(temp->right);
                    next++;
                }
            }
            else
            {
                TreeNode *temp = s2.top();
                s2.pop();
                array.push_back(temp->val);
                remain--;
                //下一行是从左到右
                if (temp->right != NULL)
                {
                    s1.push(temp->right);
                    next++;
                }
                if (temp->left != NULL)
                {
                    s1.push(temp->left);
                    next++;
                }
            }
            if (remain == 0)
            { //换行
                output.push_back(array);
                array.clear();
                remain = next;
                next = 0;
                binary++; //每换一行改变其奇偶性
            }
        }
        return output;
    }
};
int main()
{
    TreeNode *pRoot1 = new TreeNode(1);
    pRoot1->left = new TreeNode(2);
    pRoot1->right = new TreeNode(3);
    pRoot1->left->left = new TreeNode(4);
    pRoot1->left->right = new TreeNode(5);
    pRoot1->right->left = new TreeNode(6);
    pRoot1->right->right = new TreeNode(7);
    pRoot1->left->left->left = new TreeNode(8);
    pRoot1->left->left->right = new TreeNode(9);
    pRoot1->left->right->left = new TreeNode(10);
    pRoot1->left->right->right = new TreeNode(11);
    pRoot1->right->left->left = new TreeNode(12);
    pRoot1->right->left->right = new TreeNode(13);
    pRoot1->right->right->left = new TreeNode(14);
    pRoot1->right->right->right = new TreeNode(15);
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