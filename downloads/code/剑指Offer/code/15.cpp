#include <iostream>
using namespace std;

/*
二进制中1的个数：
给出一个十进制的数，计算它的二进制中1的个数；负数用补码表示。

思路一；
首先想到可以从二进制的最低位来看，因为最低位为1那么这个数为奇数，这样把这个数不断右移，就可以判断每一位，直到变为0为止。但是这样对于负数有一个问题：负数右移高位会自动补1，这样会导致死循环。所以可以不移动数，反而移动用来比较的1，将1不断左移来比较每一位。
注意过程中比较、移动尽量使用位运算来进行，因为位运算的效率要大于乘除法。
对于二进制的算法常用到位运算。

思路二：
将这个二进制数不断减1，每次减1，会导致它的二进制最右边的1变为0，它右边的0变为1（如果有的话），将减1前后的数做异或操作，就会得到前面不变的二进制数，这样每次减1就会减少一个1的二进制位，直到数变为0未知。这个方法对负数依然有用。

思路三：
c++，java中有很多关于二进制现成的方法。

测试用例：https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&tqId=11164&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution
{
public:
    int NumberOf1(int n)
    {
        int num = 0;
        if (n == 0)
        {
            return 0;
        }
        int comp = 1;
        while (comp) //由于c++中二进制有位数限制，所以最后会回到0，也可以写成小于一个较大的数
        {
            int temp = comp & n;
            if (temp != 0)
            {
                num++;
            }
            comp = comp << 1;
        }
        return num;
    }

    int NumberOf1Two(int n)
    {
        int num = 0;
        if (n == 0)
        {
            return 0;
        }
        int temp = n;
        while (temp != 0)
        {
            num++;
            temp = temp & (temp - 1);
        }
        return num;
    }
};

int main()
{
    Solution test;
    cout << test.NumberOf1(7) << " " << test.NumberOf1(-1) << endl;
    cout << test.NumberOf1Two(7) << " " << test.NumberOf1Two(-1) << endl;
    return 0;
}