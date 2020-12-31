#include <iostream>
#include <deque>
using namespace std;
/*
字符流中第一个不重复的字符：
字符串中有的字符只出现了一次，输出靠前的一个的位置，没有返回#。

思路一:用一个队列保存先后出现一次的字符。每输入一个字符，就在队列中查找，有则删去，没有则添加到队尾。

测试用例：https://www.nowcoder.com/practice/00de97733b8e4f97a3fb5c680ee10720?tpId=13&tqId=11207&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/

class Solution
{
public:
    deque<char> d;
    //Insert one char from stringstream
    void Insert(char ch)
    {
        deque<char>::iterator it = d.begin();
        for (; it != d.end(); it++)
        {
            //找到，说明出现了多次
            if (*it == ch)
            {
                //删除
                d.erase(it);
                return;
            }
        }
        //没有找到，入队
        d.push_back(ch);
        return;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        if (d.size() == 0)
        {
            return '#';
        }
        else
        {
            return d.front();
        }
    }
};

int main()
{
    Solution solution;
    solution.Insert('g');
    cout << solution.FirstAppearingOnce() << endl;
    solution.Insert('o');
    cout << solution.FirstAppearingOnce() << endl;
    solution.Insert('o');
    cout << solution.FirstAppearingOnce() << endl;
    solution.Insert('g');
    cout << solution.FirstAppearingOnce() << endl;
    solution.Insert('l');
    cout << solution.FirstAppearingOnce() << endl;
    solution.Insert('e');
    cout << solution.FirstAppearingOnce() << endl;
    return 0;
}