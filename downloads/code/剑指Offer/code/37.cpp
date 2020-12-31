#include <iostream>
#include <string.h>
#include <sstream> //stringstream
#include <stdlib.h>
#include <stdio.h>

using namespace std;
/*
序列化二叉树：
实现两个函数来序列化和反序列化二叉树。
空节点用#表示，值用!结尾

思路：序列化使用递归来全序遍历。反序列化按照先序遍历先添加根节点，再递归的添加左子树和右子树，代码中的方法是先给左右子树添加节点，如果是空再赋值NULL。

测试用例：    
https://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84
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
    char *Serialize(TreeNode *root)
    {
        //使用前序遍历来序列化
        if (root == NULL)
        {
            return NULL;
        }
        string output = "";
        output = appendToString(root, output);
        char *charStr = new char[output.size() + 1];
        for (int i = 0; i <= output.size(); i++)
        {
            if (i == output.size())
            {
                charStr[i] = '\0';
            }
            else
            {
                charStr[i] = output[i];
            }
        }
        return charStr;
        // return (char *)output.data(); //一定要加(char*)，不然会报错
    }
    //用递归来序列化
    string appendToString(TreeNode *root, string output)
    {
        if (root == NULL)
        {
            output.append("#,");
        }
        else
        {
            stringstream ss;
            string str;
            ss << root->val;
            ss >> str;
            output.append(str);
            output.append(",");
            output = appendToString(root->left, output);
            output = appendToString(root->right, output);
        }
        return output;
    }

    TreeNode *Deserialize(char *str)
    {
        if (str == NULL)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(0);
        root = addToTree(&str, root);
        return root;
    }

    TreeNode *addToTree(char **str, TreeNode *root)
    {
        int number = 0;
        if (getNumber(str, number) == true)
        {
            //是数字
            root->val = number;
            root->left = new TreeNode(0);
            root->right = new TreeNode(0);
            if (addToTree(str, root->left) == NULL)
            {
                delete root->left;
                root->left = NULL;
            }
            if (addToTree(str, root->right) == NULL)
            {
                delete root->right;
                root->right = NULL;
            }
        }
        else
        {
            root = NULL;
            //不是数字
        }
        return root;
    }

    //判断是否是数字
    bool getNumber(char **str, int &number)
    {
        int index = 0;
        if ((*str) == NULL)
        {
            return false;
        }
        else
        {
            while (true)
            {
                if ((*str)[index] == ',' || (*str)[index] == '#' || (*str)[index] == '\0')
                {
                    break;
                }
                index++;
            }
            if (index == 0 && (*str)[0] == '#')
            {
                //不是数字
                //截取
                (*str)++;
                (*str)++;
                return false;
            }
            else
            {
                //是数字
                int num = 0;
                while (**str != ',')
                {
                    num = num * 10 + (*((*str)++) - '0');
                }
                (*str)++;
                number = num;
                return true;
            }
        }
    }
};

int main()
{
    TreeNode *pRoot1 = new TreeNode(1);
    pRoot1->left = new TreeNode(2);
    pRoot1->right = new TreeNode(3);
    pRoot1->left->left = new TreeNode(4);
    //pRoot1->left->right = new TreeNode(8);
    pRoot1->right->left = new TreeNode(5);
    pRoot1->right->right = new TreeNode(6);
    Solution solution;
    char *c = solution.Serialize(pRoot1);
    cout << c << endl;
    char str[] = "1,2,4,#,#,#,3,5,#,#,6,#,#,";
    TreeNode *t = solution.Deserialize(str);
    return 0;
}