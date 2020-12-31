#include <iostream>
#include <vector>
using namespace std;
/*
把数字翻译成字符串：
按照“0翻译为a，1翻译为b，25翻译为z”的规则数字串，一串数字可能有多种翻译方法，求有多少种。

思路：接收到字符串时从前往后翻译，由于可翻译的范围0~25，所以可以选择翻译一位或者两位，从而得到f(i)=f(i+1)+f(i+2)*g(i)，f(i)表示从i开始的数字串的翻译总数，g(i)表示第i、i+1位的二位数是否在0~25的范围内，是返回1，不是返回0。
这个处理步骤还可以优化：比如再处理11258时需要分析1,1,258和11，258，这是258就要被重复分析一次；假如从后往前分析，再分析过第i位置后就把f(i)存起来，在分析左边的字符串时就可以重复使用，这是从小到大的分析方法。

*/

class Solution
{
public:
    int numberOfStr(string numbers)
    {

        int result = 0;
        if (numbers.size() == 0)
        {
            return 0;
        }
        if (numbers.size() == 1)
        {
            return 1;
        }
        if (numbers.size() >= 2)
        {
            result = numberOfStr(numbers.substr(1, numbers.size() - 1)) + isIn(numbers[0], numbers[1]) * numberOfStr(numbers.substr(2, numbers.size() - 2));
        }

        return result;
    }
    bool isIn(char a, char b)
    {
        int aa = a - '0';
        int bb = b - '0';
        if ((aa == 0) || (aa > 2) || (aa <= 2 && bb > 5))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

int main()
{
    Solution solution;
    cout << solution.numberOfStr("11258") << endl;
    return 0;
}
