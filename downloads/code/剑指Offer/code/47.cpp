#include <iostream>
#include <vector>
using namespace std;
/*
礼物的最大价值：
在一个矩阵中从左上角出发到右下角，求在经过路径上值总和的最大值。

思路：动态规划，f(i,j)表示从(i,j)出发的礼物最大值，则有f(i,j)=max(f(i+1,j),f(i,j+1))+w(i,j)，w(i,j)表示(i,j)处的礼物价值。
和上题一样，从后往前并借助辅助空间，可以减少计算重复问题。

*/
class Solution
{
public:
    int getMaxValue(vector<vector<int> > values)
    {
        int row = values.size();       //行
        int column = values[0].size(); //列
        if (row == 0 || column == 0)
        {
            return 0;
        }
        int result = 0;
        result = startIn(values, 0, 0);
        return result;
    }

    int startIn(vector<vector<int> > values, int i, int j)
    {
        int row = values.size();       //行
        int column = values[0].size(); //列
        int down = -1;
        int right = -1;
        if (i + 1 < row)
        {
            down = startIn(values, i + 1, j);
        }
        if (j + 1 < column)
        {
            right = startIn(values, i, j + 1);
        }
        if (down == -1 && right == -1)
        {
            return values[i][j];
        }
        if (down > right)
        {
            return values[i][j] + down;
        }
        else
        {
            return values[i][j] + right;
        }
    }
};
int main()
{
    int a[] = {1, 10, 3, 8, 12, 2, 9, 6, 5, 7, 4, 11, 3, 7, 16, 5};
    vector<vector<int> > values;
    values.push_back(vector<int>(a, a + 4));
    values.push_back(vector<int>(a + 4, a + 8));
    values.push_back(vector<int>(a + 8, a + 12));
    values.push_back(vector<int>(a + 12, a + 16));
    Solution solution;
    cout << solution.getMaxValue(values) << endl;
    return 0;
}