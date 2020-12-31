#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
字符串的排列：
其实就是求字符串的全排列。字符可能有重复。

思路：用递归的思想，将一整个字符串看成两部分：第一个字符和后面的字符串。第一个可以取整个字符串的所有字符，后面的字符串可以取它的全排列。

测试用例：
*/

class Solution
{
public:
    vector<string> Permutation(string str)
    {
        vector<string> output;
        if (str.size() == 0)
        {
            return output;
        }
        if (str.size() == 1)
        {
            output.push_back(str);
            return output;
        }
        recursize(str, 0, output);
        sort(output.begin(), output.end());
        return output;
    }

    void recursize(string str, int k, vector<string> &output)
    {
        if (str.size() - 1 == k)
        {
            //构成一次全排列
            //查找是否存在
            vector<string>::iterator result = find(output.begin(), output.end(), str);
            if (result == output.end())
            {
                //没找到
                output.push_back(str);
            }
            return;
        }
        for (int i = k; i < str.size(); i++)
        {
            swap(str, k, i);
            recursize(str, k + 1, output);
            swap(str, k, i);
        }
    }

    //交换字符串中的两个字符
    void swap(string &str, int i, int j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
};
int main()
{
    vector<string> output;
    Solution solution;
    output = solution.Permutation("abc");
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    return 0;
}