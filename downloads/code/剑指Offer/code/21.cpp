#include <iostream>
#include <vector>
using namespace std;
/*
调整数组的顺序使奇数位于偶数前面：

思路：维护两个指针，第一个指针从前到后搜索偶数，第二个指针从后向前搜索奇数；当两个都搜到时，交换两个数字，继续搜索。
*/

//没有稳定性的方法
class Solution2
{
public:
    void reOrderArray(vector<int> &array)
    {
        int a = 0, b = array.size() - 1;
        while (a < b)
        {
            while (array[a] % 2 != 0)
            {
                a++;
            }
            while (array[b] % 2 == 0)
            {
                b--;
            }
            if (a >= b)
            {
                break;
            }
            else
            {
                int temp = array[a];
                array[a] = array[b];
                array[b] = temp;
            }
        }
    }
};

//保证稳定性的方法，则只能顺次移动或相邻交换
class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        //相对位置不变，稳定性
        //插入排序的思想
        int m = array.size();
        int k = 0; //记录已经摆好位置的奇数的个数
        for (int i = 0; i < m; i++)
        {
            if (array[i] % 2 == 1) //奇数
            {
                int j = i; //记录奇数未知
                while (j > k)
                { //j >= k+1
                    int tmp = array[j];
                    array[j] = array[j - 1];
                    array[j - 1] = tmp;
                    j--;
                }
                k++;
            }
        }
    }
};

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(5);
    v.push_back(7);
    v.push_back(8);
    v.push_back(10);
    v.push_back(21);
    v.push_back(22);
    Solution solution;
    solution.reOrderArray(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}