#include <iostream>
#include <vector>
using namespace std;
/*
栈的压入、弹出序列：
判断给出的弹出序列是否是给出压入序列的一种弹出情况。

思路：构建一个辅助栈，结合弹出序列从前往后的元素和在压入序列中的位置，在辅助栈中压栈并出栈。如果弹出序列元素和辅助栈顶元素相同，则将辅助栈出栈；如果不相同，则将压入序列的元素一直压入，直到压到弹出序列元素和辅助栈顶元素相同。

测试用例：https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking()
*/

class Solution
{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        if (pushV.size() == 0 || popV.size() == 0)
        {
            return false;
        }
        int tt = pushV[0];
        vector<int>::reverse_iterator riter;
        vector<int> pushVV;
        //pushV反转
        for (riter = pushV.rbegin(); riter != pushV.rend(); riter++)
        {
            pushVV.push_back(*riter);
        }
        vector<int> temp;
        for (int i = 0; i < popV.size(); i++)
        {
            if (temp.size() > 0 && temp[temp.size() - 1] == popV[i])
            { //直接将辅助栈出栈
                temp.pop_back();
            }
            else //将压入序列中这个元素之前的元素都压到辅助栈中
            {
                while (true)
                {
                    if (pushVV.size() <= 0)
                    {
                        return false;
                    }
                    int t = pushVV[pushVV.size() - 1];
                    pushVV.pop_back();
                    if (t == popV[i])
                    {
                        temp.push_back(t);
                        break;
                    }
                    else
                    {
                        temp.push_back(t);
                        continue;
                    }
                }
                temp.pop_back();
            }
        }
        return true;
    }
};
int main()
{
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {3, 5, 4, 2, 1};
    vector<int> a(array1, array1 + 5);
    vector<int> b(array2, array2 + 5);
    Solution solution;
    if (solution.IsPopOrder(a, b) == false)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    return 0;
}