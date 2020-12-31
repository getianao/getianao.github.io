#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
/*
数组中只出现一次的两个数字：
改为数组中除了一个数字只出现一次，其他数字均出现了三次，找出这两个数字，要求时间复杂度是O(n)，空间复杂度是O(1).

思路：这里又变成了三次，异或运算是针对2次的，但是依然可以沿用位运算的思想，将每一位对应相加（没有进位），结果中可以被3整除的位则是出现三次的，不能被3整除的位对应是出现一次的。
*/

class Solution
{
public:
    void FindNumsAppearOnce(vector<int> data, int *num1)
    {
        int *a = new int[16];
        int result = 0;
        for (int i = 0; i < data.size(); i++)
        {
            bitsCalculation(a, data[i]);
        }
        for (int i = 0; i < 16; i++)
        {
            if (a[i] != 0 && a[i] % 3 == 0)
            {
                //可以被3整除
                result = result + pow(2, i);
            }
        }
        num1[0] = result;
    }

    void bitsCalculation(int *a, int b)
    {
        int index = 0;
        while (b != 0)
        {

            if (b % 2 == 1)
            {
                a[index]++;
            }
            index++;
            b = b >> 1; //右移一位
        }
    }
};
int main()
{
    int a[] = {1, 1, 3, 1};
    vector<int> data(a, a + 4);
    Solution solution;
    int *num1 = new int;
    int *num2 = new int;
    solution.FindNumsAppearOnce(data, num1);
    cout << "num1:" << *num1 << endl;
    return 0;
}