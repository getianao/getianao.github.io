#include <iostream>
#include <vector>
using namespace std;
/*
股票的最大利润：
给出了股票在一段时间节点的价格，计算在这段时间内买入并卖出股票可以得到的最大收益。
就是找左边的最小值和右边的最大值。

思路：从头至尾的扫描整个数组，将指针指向的值当作卖出值，并计算在此之前的数字的最小值。记录这个过程中的最大插值。时间复杂度时O(n).

*/

class Solution
{
public:
    int getMaxDiff(vector<int> price)
    {
        int maxDiff = 0, minPrice = price[0];
        for (int i = 1; i < price.size(); i++)
        {
            if (minPrice <= price[i] && maxDiff < price[i] - minPrice)
            {
                maxDiff = price[i] - minPrice;
            }
            if (minPrice > price[i])
            {
                minPrice = price[i];
            }
        }
        return maxDiff;
    }
};
int main()
{
    Solution soluton;
    int a[] = {9, 11, 8, 5, 7, 12, 16, 14};
    vector<int> price(a, a + 8);
    cout << soluton.getMaxDiff(price) << endl;
    return 0;
}