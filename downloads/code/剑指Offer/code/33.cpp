#include <iostream>
#include <vector>
using namespace std;
/*
二叉搜索树的后序遍历序列：
判断给出的序列是否是某个二叉搜索树的后序遍历序列。

思路；根据二叉搜索树的特点，序列中最后一个元素是根节点，前半部分比它小的元素是左子树，后半部分比它大的元素是右子树。
所以可以直接将二叉搜索树的后序遍历求出来比较，或者是用递归的方法直接比较。
但是这里没有给定二叉搜索树，只要序列满足规律即可。

测试用例：https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&tqId=11176&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/
class Solution
{
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.size() > 0)
        {
            if (sequence.size() == 1)
            {
                return true;
            }
            vector<int> left, right;
            int divide;
            int root = sequence[sequence.size() - 1];
            //找左右子树的分界点
            for (int i = 0; i <= sequence.size() - 2; i++)
            {
                if (root < sequence[i])
                {
                    divide = i;
                    break;
                }
                else
                {
                    left.push_back(sequence[i]);
                }
            }
            //验证右子树都大于根节点
            for (int i = divide; i <= sequence.size() - 2; i++)
            {
                if (root > sequence[i])
                {
                    return false;
                }
                else
                {
                    right.push_back(sequence[i]);
                }
            }
            bool leftBool = true, rightBool = true;
            if (left.size() > 0)
            {
                leftBool = VerifySquenceOfBST(left);
            }
            if (right.size() > 0)
            {
                rightBool = VerifySquenceOfBST(right);
            }

            return leftBool && rightBool;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    int a[] = {5, 7, 6, 9, 11, 10, 8};
    vector<int> sequence(a, a + 7);
    Solution solution;
    if (solution.VerifySquenceOfBST(sequence) == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}