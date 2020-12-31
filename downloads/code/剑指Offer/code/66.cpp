#include <iostream>
#include <vector>
using namespace std;
/*
构建乘积数组：
给出一个长度为n的数组A，返回另一个数组B，B中坐标为i的元素值为A中除了坐标为i的所有元素的乘积。
不能使用除法。

思路一：B中每个去算一遍，时间复杂度是O(n^2)

思路二：把B中的乘积看成两部分B(i)=C(i)*D(i)=(A(0)*...*A(i-1))*(A(i+1)*...*A(n-1))。一共对B做两次遍历，第一次将C(i)都乘到B中（从前向后），第二次把D(i)都乘到B中（从后向前）。

测试用例：nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46?tpId=13&tqId=11204&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/
class Solution
{
public:
    vector<int> multiply(const vector<int> &A)
    {
        vector<int> B;
        int temp1 = 1;
        int temp2 = 1;
        for (int i = 0; i < A.size(); i++)
        {
            B.push_back(1);
            B[i] *= temp1;
            temp1 *= A[i];
        }
        for (int i = A.size() - 1; i >= 0; i--)
        {
            B[i] *= temp2;
            temp2 *= A[i];
        }
        return B;
    }
};
int main()
{
    Solution solution;
    int a[] = {1, 2, 3, 4};
    vector<int> A(a, a + 4);
    vector<int> B = solution.multiply(A);
    for (int i = 0; i < B.size(); i++)
    {
        cout << B[i] << endl;
    }
    return 0;
}