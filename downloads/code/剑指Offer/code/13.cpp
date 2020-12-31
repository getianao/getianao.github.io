#include <iostream>
#include <string.h>
using namespace std;
/*
机器人的运动范围：
给出一个已知长宽的矩阵，机器人从(0,0)出发，它只能向四周的四个方块前进，并且给定k，要求所在的方块坐标必须满足数位相加小于等于k；求k最多能够到达多少个格子。访问过的方块不能再次访问,可以包括多条路径。

思路：
这道题很像上一题“矩阵中的路径”，不同之处在于查找距离是在四个方向中找出一个正确方向，而这道题四个方向的都需要去探索、统计；所以这道题不需要回溯，只需要递归就行了。尝试访问所在方格四周的方格，每访问一个，再访问它的四周时，在计数变量里加1，如果此块皆不可访问，返回0。

测试用例：https://www.nowcoder.com/practice/6e5207314b5241fb83f2329e89fdecc8?tpId=13&tqId=11219&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

*/

class Solution
{
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if (rows <= 0 || cols <= 0 || threshold < 0)
        {
            return 0;
        }
        int *visited = new int[rows * cols];
        memset(visited, 0, sizeof(int) * rows * cols);
        int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
        return count;
    }

    int movingCountCore(int threshold, int rows, int cols, int i, int j, int *visited)
    {
        int count = 0;
        if (i < 0 || i >= rows || j < 0 || j >= cols)
        { //数组越界
            return 0;
        }
        if (visited[i * cols + j] == 0 && check(threshold, i, j) == true)
        { //可以访问
            visited[i * cols + j] = 1;
            count = 1 + movingCountCore(threshold, rows, cols, i - 1, j, visited) + movingCountCore(threshold, rows, cols, i + 1, j, visited) + movingCountCore(threshold, rows, cols, i, j - 1, visited) + movingCountCore(threshold, rows, cols, i, j + 1, visited);
        }
        return count;
    }

    //判断坐标数位之和是否小于threshold
    bool check(int threshold, int i, int j)
    {
        int ii = getDigitSum(i);
        int jj = getDigitSum(j);
        if (threshold < ii + jj)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    //计算数位之和
    int getDigitSum(int n)
    {
        int sum = 0;
        while (n != 0)
        {
            sum = sum + n % 10;
            n = n / 10;
        }
        return sum;
    }
};

int main()
{
    Solution test;
    cout << test.movingCount(5, 10, 10) << endl;
    return 0;
}