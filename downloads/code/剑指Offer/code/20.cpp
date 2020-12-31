#include <iostream>
using namespace std;
/*
表示数值的字符串：

思路：可以将字符串分为3部分：整数部分，小数部分，指数部分

*/
class Solution
{
public:
    bool isNumeric(char *string)
    {
        bool num;
        if (string == NULL)
        {
            return false;
        }
        //首先扫描整数部分
        num = scanInteger(&string);
        if (*string == '.') //省略整数部分情况
        {
            /*这里有几种可能：
            ①有整数部分但在上一步被截取:true||?
            ②没有整数部分，简写为.234:false||true
            ③.后正常写小数部分:?||true
            ④.后省略小数部分，如2.:||true||false
            */
            ++string;
            num = scanUnsignedInteger(&string) || num;
        }
        if (*string == 'e' || *string == 'E')
        {
            //e后必须时整数
            ++string;
            num = scanInteger(&string) && num;
        }
        return num && *string == '\0';
    }
    bool scanInteger(char **string)
    {
        if (**string == '+' || **string == '-')
        {
            (*string)++;
        }
        return scanUnsignedInteger(string);
    }

    bool scanUnsignedInteger(char **string)
    {
        char *str = *string;
        while (**string != '\0' && **string >= '0' && **string <= '9')
        {
            (*string)++;
        }
        return str < *string;
    }
};

int main()
{
    char string[] = "+42.e-12";
    Solution Solution;
    if (Solution.isNumeric(string))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}