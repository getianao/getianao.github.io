#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
/*
将数组排成最小的数：

思路一；考虑数组元素的全排列，但是有大数问题，且时间复杂度太大。

思路二：设计一种元素的排列方法，将数组内的元素排序后拼接即可得到答案；

测试用例：https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?tpId=13&tqId=11185&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
int numLength;
char getBig(string a)
{
    char max = -1;
    for (int i = 0; i < a.size(); i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}
bool compare(const string &a, const string &b)
{
    string aa = a;
    string bb = b;
    //❗注意一定是用数字中值最大的一位填充
    string str1(numLength, getBig(aa));
    string str2(numLength, getBig(bb));
    aa = (aa + str1).substr(0, numLength);
    bb = (bb + str2).substr(0, numLength);
    for (int i = 0; i < numLength; i++)
    {
        if (aa[i] > bb[i])
        {
            return false;
        }
        if (aa[i] < bb[i])
        {
            return true;
        }
        if (aa[i] == bb[i])
        {
            continue;
        }
    }
    return true;
}

class Solution
{
public:
    string PrintMinNumber(vector<int> numbers)
    {
        vector<string> sv;
        if (numbers.size() == 0)
        {
            return "";
        }
        numLength = getLength(numbers[0]);
        //查找最长的数
        for (int i = 1; i < numbers.size(); i++)
        {
            int tLength = getLength(numbers[i]);
            if (tLength > numLength)
            {
                numLength = tLength;
            }
        }
        if (numLength <= 0)
        {
            return "";
        }
        //转换成字符串
        for (int i = 0; i < numbers.size(); i++)
        {
            stringstream ss;
            ss << numbers[i];
            string newStr = ss.str();
            sv.push_back(newStr);
        }
        //排序
        sort(sv.begin(), sv.end(), compare);
        string result = "";
        for (int i = 0; i < sv.size(); i++)
        {
            result = result + sv[i];
        }
        return result;
    }

    int getLength(int n)
    {
        int length = 0;
        while (n != 0)
        {
            n = n / 10;
            length++;
        }
        return length;
    }
};
int main()
{
    vector<int> input;
    input.push_back(3334);
    input.push_back(3);
    input.push_back(3333332);
    Solution solution;
    cout << solution.PrintMinNumber(input) << endl;
    return 0;
}