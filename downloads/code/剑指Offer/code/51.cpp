#include <iostream>
#include <vector>
using namespace std;
/*
数组中的逆序对：
按照在数组中的位置，前面的元素大于后面的元素，构成一对逆序。求数组中的逆序对数。

思路一：扫描整个数组，每次确定一个元素并在它后面的元素中虚招比它小的。时间复杂度是O(n^2)。

思路二：从小到大计算逆序数，类似归并排序。copy数组用来存储排序后的数组。
把数组一分为二，先分别计算两个子数组中的逆序数，然后计算两个子数组之间的逆序数。在分别计算两个子数组中的逆序数时，两个子数组内部已被排序。
用两个指针分别指向两个数组中最大的元素，然后比较，如果前一个大于后一个，则后一个数组中的剩余元素都可以构成逆序对，然后前一个指针前移（尝试前一个再变小一点，看能否构成）；如果前一个小于后一个，则把后一个前移（尝试后一个再变小一点，看能否构成），这个过程中顺便把这两个数组合并并排序。


*/

class Solution
{
public:
    int InversePairs(vector<int> data)
    {
        if (data.size() == 0)
        {
            return 0;
        }
        vector<int> copy; //排序的数组
        for (int i = 0; i < data.size(); i++)
        {
            copy.push_back(data[i]);
        }
        int count = InversePairsCore(data, copy, 0, data.size() - 1);
        return count % 1000000007;
    }

    int InversePairsCore(vector<int> &data, vector<int> &copy, int start, int end)
    {
        if (start == end)
        { //数组中只有一个元素
            copy[start] = data[start];
            return 0;
        }
        int length = (end - start) / 2; //分成两个子数组，统计子数组内的逆序数
        //❗注意这里传参是copy、data，这样就不需要再函数末尾手动的将copy复制给data，会造成超时
        int left = InversePairsCore(copy, data, start, start + length);
        int right = InversePairsCore(copy, data, start + length + 1, end);
        int i = start + length; //前半部分的最后一个元素
        int j = end;            //后半部分的最后一个元素
        int indexCopy = end;    //排序数组中的指针指向最后一个元素
        int count = 0;
        while (i >= start && j >= start + length + 1) //i、j指针在各自数组内
        {
            if (data[i] > data[j])
            {
                //构成逆序，逆序数是后面数组内剩下的元素数量
                //向前移动前一个数组指针
                copy[indexCopy--] = data[i--];
                count = (count + j - start - length - 1 + 1) % 1000000007;
            }
            else
            {
                //不构成逆序，向前移动后一个数组指针
                copy[indexCopy--] = data[j--];
            }
        }
        for (; i >= start; i--)
        {
            copy[indexCopy--] = data[i];
        }
        for (; j >= start + length + 1; j--)
        {
            copy[indexCopy--] = data[j];
        }

        return (left + right + count) % 1000000007;
    }
};
int main()
{

    int a[] = {7, 5, 6, 4};
    vector<int> data(a, a + 4);
    Solution solution;
    cout << solution.InversePairs(data) << endl;
    return 0;
}