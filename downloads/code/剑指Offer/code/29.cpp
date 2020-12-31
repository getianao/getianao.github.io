#include <iostream>
#include <vector>
using namespace std;
/*
顺时针打印矩阵：
由外到里顺时针旋转。

思路：注意到每一圈开始，行号和列号是相同的
*/

class Solution
{
public:
    vector<int> printMatrix(vector<vector<int> > matrix)
    {
        vector<int> output;
        int row = matrix.size();       //行
        int column = matrix[0].size(); //列
        int startX = 0, endX = column - 1, startY = 0, endY = row - 1;
        while (true)
        {
            if (startX > endX)
            {
                break;
            }
            for (int i = startX; i <= endX; i++)
            {
                output.push_back(matrix[startY][i]);
            }
            startY++;
            if (startY > endY)
            {
                break;
            }
            for (int i = startY; i <= endY; i++)
            {
                output.push_back(matrix[i][endX]);
            }
            endX--;
            if (endX < startX)
            {
                break;
            }
            for (int i = endX; i >= startX; i--)
            {
                output.push_back(matrix[endY][i]);
            }
            endY--;
            if (endY < startY)
            {
                break;
            }
            for (int i = endY; i >= startY; i--)
            {
                output.push_back(matrix[i][startX]);
            }
            startX++;
        }
        return output;
    }
};

int main()
{
    int a[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    vector<vector<int> > matrix;
    vector<int> array1(a, a + 4);
    vector<int> array2(a + 4, a + 8);
    vector<int> array3(a + 8, a + 12);
    vector<int> array4(a + 12, a + 16);
    matrix.push_back(array1);
    matrix.push_back(array2);
    matrix.push_back(array3);
    matrix.push_back(array4);
    Solution solution;
    vector<int> array = solution.printMatrix(matrix);
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}