#include <iostream>
using namespace std;
/*
反转单词顺序：
将句子中的单词反转顺序，单词内字母夫反转；标点符号和前一个单词看成一体 单词之间用空格分割。

思路：两次反转：第一次将整个字符串反转，第二次将单词反转。

测试用例：https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3?tpId=13&tqId=11197&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

*/
class Solution
{
public:
    string ReverseSentence(string str)
    {
        string result = reverse(str, 0, str.size() - 1);
        int start = 0, end = 0;
        for (int i = 0; i < result.size(); i++)
        {
            if (result[i] == ' ')
            {
                end = i - 1;
                result = reverse(result, start, end);
                start = i + 1;
            }
            else
            {
                if (i == result.size() - 1)
                {
                    //最后一个单词
                    end = i;
                    result = reverse(result, start, end);
                    start = i + 1;
                }
            }
        }
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
    cout << solution.ReverseSentence("I am a student.") << endl;
    return 0;
}