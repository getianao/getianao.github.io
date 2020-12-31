#include <iostream>
using namespace std;
/*
将字符串转化为整数：
主要是注意非法输入：
是否有正负号，字符串长度，是否有非法字符，是否超过整数范围；

测试用例：https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/
enum Status
{
    kValid = 0,
    kInvalid
};
//是否为正常输入
int status = kValid;
class Solution
{
public:
    int StrToInt(string str)
    {
        status = kInvalid;
        long long num = 0;
        bool minus = true; //默认为整数
        if (str.empty() != true)
        {
            //先判断是否有符号
            if (str[0] == '+')
            {
                minus = true;
                str = str.substr(1, str.size() - 1);
            }
            if (str[0] == '-')
            {
                minus = false;
                str = str.substr(1, str.size() - 1);
            }
            //去掉符号后是否为空
            if (str.empty() == false)
            {
                num = strToIntCore(str, minus);
            }
        }
        return (int)num;
    }

    long long strToIntCore(string str, bool minus)
    {
        long long num = 0;
        int flag; //判断正负
        if (minus == true)
        {
            flag = 1;
        }
        else
        {
            flag = -1;
        }
        int i = 0;
        for (; i < str.size(); i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                num = num * 10 + flag * (str[i] - '0');
                if ((flag == 1 && num > 0x7fffffff) || (flag == -1 && num < (signed int)0x80000000))
                {
                    //超出整数范围
                    num = 0;
                    break;
                }
            }
            else
            {
                num = 0;
                break;
            }
        }
        if (i == str.size())
        {
            status = kValid;
        }
        return num;
    }
};
int main()
{
    Solution solution;
    int result = solution.StrToInt("+2147483647");
    cout << result << endl;
    return 0;
}