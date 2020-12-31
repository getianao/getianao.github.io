#include <iostream>
#include <string>
using namespace std;
/*
正则表达式的匹配：
.表示任意一个字符，*表示其前面一个字符任意多个（包括0次）。
注意.*的含义：任意字符任意多个（包括0次）。

思路一：按照理解直接写，之前写的时候忘记了.*的情况。

思路二：递归，*有两种匹配方式，一种是0次的特殊情况，这是直接将模式+2、字符串不变，还有一种是重复n次，这时是模式不变、字符串+1；当指针所指字符不相同时，之能用第一种匹配方式，相同时用第二种。

测试用例：https://www.nowcoder.com/practice/45327ae22b7b413ea21df13ee7d6429c?tpId=13&tqId=11205&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
class Solution1
{
public:
    bool match(char *str, char *pattern)
    {
        int s = 0, p = 0;
        while (true)
        {
            if (str == NULL || pattern == NULL)
            {
                return false;
            }
            if (str[s] == '\0' && pattern[p] == '\0')
            {
                return true;
            }
            if (str[s] != '\0' && pattern[p] == '\0')
            {
                return false;
            }
            // if (str[s] == '\0' && pattern[p] != '\0')
            // {
            //     return false;
            // }

            if (pattern[p + 1] == '*') //指针后面一个字符，需要首先判断
            {
                if (str[s] == pattern[p])
                {
                    //相同
                    if (pattern[p] == pattern[p + 2]) //a*a的情况，可能匹配前一个也可能匹配后一个
                    {
                        int num = 0, index = 2; //i表示a*后有几个a
                        while (true)
                        {
                            if (pattern[p + index] == pattern[p])
                            {
                                num++;
                            }
                            else
                            {
                                break;
                            }
                            index++;
                        }
                        for (int i = 0; i < num; i++)
                        {
                            if (str[s + i] != pattern[p])
                            {
                                return false;
                            }
                        }
                        while (str[s] == pattern[p])
                        {
                            s++;
                        }
                        p = p + 2 + num;
                        continue;
                    }
                    else //a*b的情况
                    {
                        if (str[s + 1] == pattern[p]) //后面还有
                        {
                            s++;
                            continue;
                        }
                        else //后面没了
                        {
                            p = p + 2;
                            s++;
                            continue;
                        }
                    }
                }
                else
                { //不相同，只可能是出现了0次
                    p = p + 2;
                    continue;
                }
            }

            if (pattern[p] == '.')
            {
                p++;
                s++;
                continue;
            }

            if (pattern[p] == str[s])
            {
                p++;
                s++;
                continue;
            }
            else
            {
                return false;
            }
        }
    }
};


class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (*str == '\0' && *pattern == '\0')
            return true;
        if (*str != '\0' && *pattern == '\0')
            return false;
        //if the next character in pattern is not '*'
        if (*(pattern+1) != '*')
        {
            //直接匹配或者是.
            if (*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str+1, pattern+1);
            else
                return false;
        }
        //if the next character is '*'
        else
        {
           
            if (*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str, pattern+2) || match(str+1, pattern); //两种匹配方法
            else
                return match(str, pattern+2);
        }
    }
};

int main()
{
    char str[] = "aaa";
    char pattern[] = "ab*ac*a";
    Solution solution;
    if (solution.match(str, pattern))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}