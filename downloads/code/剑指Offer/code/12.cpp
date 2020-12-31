#include <iostream>
#include <string.h>
using namespace std;
/*
矩阵中的路径：
判断是否能在一个字符矩阵中寻找一条路经，构成要求的字符串；已经经过的字符不能再次经过。

思路：
回溯的思想：先在矩阵中寻找字符串的第一个字符作为起点，然后再它的周围尝试进入下一个字符，没有满足要求的话就返回上一个字符继续寻找。

测试用例：https://www.nowcoder.com/practice/c61c6999eecb4b8f88a98f66b273a3cc?tpId=13&tqId=11218&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution
{
public:
    bool hasPath(char *matrix, int rows, int cols, char *str)
    {
        if (matrix == NULL || rows < 0 || cols < 0 || str == NULL)
        {
            return false;
        }
        int *visited = new int[rows * cols];
        memset(visited, 0, sizeof(int) * rows * cols);
        int strLength = 0;
        //尝试从矩阵的每一个元素进入
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (hasPathCore(matrix, rows, cols, str, i, j, strLength, visited) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
    //回溯的核心函数
    bool hasPathCore(char *matrix, int rows, int cols, char *str, int i, int j, int strLength, int *visited)
    {
        bool hasNext = false;
        if (rows < 0 || cols < 0 || matrix == NULL || str == NULL)
        {
            return false;
        }
        if (str[strLength] == '\0')
        { //结束
            return true;
        }
        if (matrix[(i)*cols + j] == str[strLength] && visited[(i)*cols + j] == 0)
        { //当前字符匹配
            strLength++;
            visited[(i)*cols + j] = 1;
            //再周围尝试查找下一个字符
            hasNext = hasPathCore(matrix, rows, cols, str, i, j - 1, strLength, visited) || hasPathCore(matrix, rows, cols, str, i, j + 1, strLength, visited) || hasPathCore(matrix, rows, cols, str, i - 1, j, strLength, visited) || hasPathCore(matrix, rows, cols, str, i + 1, j, strLength, visited);
            if (!hasNext)
            { //四周都不行，回溯
                strLength--;
                visited[(i)*cols + j] = 0;
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution test;
    char matrix[] = "abtgcfcsjdeh";
    if (test.hasPath(matrix, 3, 4, "bfce") == true)
    {
        cout << "exist!" << endl;
    }
    else
    {
        cout << "not exist!" << endl;
    }
    if (test.hasPath(matrix, 3, 4, "bfcec") == true)
    {
        cout << "exist!" << endl;
    }
    else
    {
        cout << "not exist!" << endl;
    }
    return 0;
}