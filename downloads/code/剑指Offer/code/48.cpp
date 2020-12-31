#include <iostream>
#include <string>
using namespace std;
/*
最长不含重复字符的子字符串:

思路一：枚举；长度为n的子字符串有O(n^2)个，扫描每一个需要O(n)的时间，一共需要O(n^3)的时间。

思路二：动态规划，f(i)表示已第i个字符结尾的最长不含重复字符的子字符串的长度，则有
f(i)=|-- f(i-1)+1   第i个元素和之前的没有重复
    |--  d          第i个元素和之前的有重复
d表示两个重复元素之间的距离。
需要用一个辅助数组来存储最长不含重复字符的子字符串的长度。

*/
class Solution
{
public:
    int getMax(string str)
    {
        int length = str.size();
        int *max = new int[length]; //以第i位结尾的最长不含重复字符的子字符串从max位开始
        int m = -1;
        for (int i = 0; i < length; i++)
        {
            getMaxToI(max, str, i);
        }
        for (int i = 0; i < length; i++)
        {
            if (max[i] > m)
            {
                m = max[i];
            }
        }
        return m;
    }
    void getMaxToI(int *max, string str, int i)
    {
        int length = str.size();
        if (i == 0)
        {
            max[i] = 1;
            return;
        }
        int dist = isRepeat(i - max[i - 1], i, str);
        if (dist == 0)
        {
            //第i个元素和之前的没有重复
            max[i] = max[i - 1] + 1;
        }
        else
        {
            //第i个元素和之前的有重复
            max[i] = dist;
        }
    }
    //判断str的第i位在start到i-1位是否出现过，出现则返回距离
    int isRepeat(int start, int i, string str)
    {
        int dist = 0;
        for (int j = start; j < i; j++)
        {
            if (str[j] == str[i])
            {
                dist = j - i;
                break; //可以直接退出
            }
        }
        return dist;
    }
};
int main()
{
    Solution solution;
    cout << solution.getMax("arabcacfr") << endl;
    return 0;
}