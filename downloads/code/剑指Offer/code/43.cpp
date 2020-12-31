#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/*
1~n整数中1出现的次数：
计算这n个整数的十进制表示中1出现的次数之和。

思路一：一般算法；对于每个数，通过对10取余依次判断每一位是否是1。时间复杂度时O(nlogn)。

思路二：利用数据的规律；以1~21345为例，分为两个部分：1~1345和1336~21345，前一部分用递归计算；后一部分首先计算最高位1的次数，如果最高位等于1，次数为去掉最高位的数加1.如果大于1，次数为10^k，k为去掉最高位的数的长度（如10000~19999为10000)；然后计算除了最高位剩余位数1出现的次数，为最高位数字*去掉最高位的数的长度*10^(k-1)，k为去掉最高位的数的长度减1。
时间复杂度为O(logn)

测试用例：https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&tqId=11184&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/
class Solution
{
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n <= 0)
        {
            return 0;
        }
        stringstream ss;
        ss << n;
        string s1 = ss.str();
        return NumberOf1(s1);
    }

    //转换成字符串操作
    int NumberOf1(string str)
    {
        if (str.size() == 0 || str[0] < '0' || str[0] > '9')
        {
            return 0;
        }
        if (str.size() == 1 && str[0] == '0')
        {
            return 0;
        }
        if (str.size() == 1 && str[0] == '1')
        {
            return 1;
        }
        int length = str.size();
        //最高位
        int numFirstDigit = 0;
        int first = str[0] - '0';
        if (first == 1)
        {
            //如果最高位等于1，次数为去掉最高位的数加1
            string s = str.substr(1, length - 1);
            istringstream is(s); //构造输入字符串流，流的内容初始化为str字符串
            is >> numFirstDigit;
            numFirstDigit++;
        }
        else
        {   //判断为0容易遗漏
            if (first == 0)
            {
                return NumberOf1(str.substr(1, length - 1));
            }
            //如果大于1，次数为10^k，k为去掉最高位的数的长度（如10000~19999为10000)
            int k = 0;
            int r = 1;
            while (k < length - 1)
            {
                r = r * 10;
                k++;
            }
            numFirstDigit = r;
        }
        //计算除了最高位剩余位数1出现的次数，为最高位数字*去掉最高位的数的长度*10^(k-1)，k为去掉最高位的数的长度减1。
        int kk = 0;
        int rr = 1;
        while (kk < length - 2)
        {
            rr = rr * 10;
            kk++;
        }
        int numOthorDigit = first * (length - 1) * rr;
        int numRecursize = NumberOf1(str.substr(1, length - 1));
        return numFirstDigit + numOthorDigit + numRecursize;
    }
};
int main()
{
    Solution solution;
    cout << solution.NumberOf1Between1AndN_Solution(10000) << endl;
    return 0;
}
