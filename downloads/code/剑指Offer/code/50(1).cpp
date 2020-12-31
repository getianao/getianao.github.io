#include <iostream>
#include <map>
using namespace std;
/*
第一个只出现一次的字符：
字符串中有的字符只出现了一次，输出靠前的一个的位置，没有返回-1。

思路一：用一个容器来存储字符出现的次数，第二次扫描字符串时才容器中查询，输出出现次数为1的字符。容器选择为hash表，因为查找的时间复杂度时O(1)。
也可以自己通过一个数组要实现简单的hash表，注意确定数组大小。

测试用例：https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&tqId=11187&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/
class Solution
{
public:
    int FirstNotRepeatingChar(string str)
    {
        map<char, int> charMap;
        for (int i = 0; i < str.size(); i++)
        {
            map<char, int>::iterator iter1;
            iter1 = charMap.find(str[i]);
            if (iter1 == charMap.end())
            {
                //没有找到，插入
                charMap[str[i]] = 1;
            }
            else
            {
                //找到，次数加1
                charMap[str[i]]++;
            }
        }
        for (int i = 0; i < str.size(); i++)
        {
            map<char, int>::iterator iter1;
            iter1 = charMap.find(str[i]);
            if (charMap[str[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    Solution solution;
    cout << solution.FirstNotRepeatingChar("abaccdeff") << endl;
    return 0;
}