#include <iostream>
using namespace std;
/*
左旋转字符串：
将字符串前面的若干个字符移动到字符串后面

思路：两次反转

测试用例：https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?tpId=13&tqId=11196&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/
class Solution
{
public:
    string LeftRotateString(string str, int n)
    {
        if (n < 0 || n > str.size())
        {
            return "";
        }
        string result = reverse(str, 0, str.size() - 1);
        result = reverse(result, 0, result.size() - 1 - n);
        result = reverse(result, result.size() - 1 - n + 1, result.size() - 1);
        return result;
    }
    string reverse(string str, int start, int end)
    {
        string s(str);
        for (int i = start; i <= end; i++)
        {
            s[end + start - i] = str[i];
        }
        return s;
    }
};
int main()
{
    Solution solution;
    cout << solution.LeftRotateString("abcdefg", 2) << endl;
    return 0;
}