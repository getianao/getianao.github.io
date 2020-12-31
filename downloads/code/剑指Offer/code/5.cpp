#include <iostream>
#include <string.h>
using namespace std;
/*
空格替换：
将字符串中的空格替换为%20

思路一：一边找一边替换
当找到空格时后面所有的字符向后移动。这样操作适合这样的情况：要求在原字符串上操作；保证字符串有足够空间；
时间复杂度为O(n^2)

思路二：先全部扫描一遍再换
首先全部扫描一遍确定替换后的总长度，然后再替换，从前往后或从后向前都可，需要开辟新的内存。如果要在原内存上操作，则需要从后向前，因为这样不会覆盖掉已有的数据，也避免了多次移动。
时间复杂度为O(n)

测试用例：https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution
{
public:
    void replaceSpace(char *str, int length)
    {
        int strLength = 0, blankNum = 0, newLength;
        for (int i = 0; i < length; i++)
        {
            if (str[i] == '\0')
            { //'\0'是不算在长度里的
                break;
            }
            strLength++;
            if (str[i] == ' ')
            {
                blankNum++;
            }
        }
        newLength = strLength + 2 * blankNum;
        if (length < newLength)
        {
            return;
        }

        int strPtr = strLength, newStrPtr = newLength;
        for (; strPtr >= 0; strPtr--)
        {
            if (str[strPtr] != ' ')
            {
                str[newLength--] = str[strPtr];
            }
            else
            {
                str[newLength--] = '0';
                str[newLength--] = '2';
                str[newLength--] = '%';
            }
        }
    }
};

int main()
{
    Solution test;
    char *str = new char[26];
    //memset(str,0,sizeof(char)*4);
    strcpy(str, "  we are happy ");
    test.replaceSpace(str, 26);
    cout << str << endl;
}
