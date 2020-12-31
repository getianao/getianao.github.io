#include <iostream>
#include <vector>
#include <set>
#include <functional>
using namespace std;
/*
最小的k个数:
k大于数组长度时输出数组为空。

思路一：类似于第39题，通过查找元素的坐标来找前k小的元素。这养的做法要求数组可以被修改。
❓时间复杂度为什么是O(n)

思路二：维护一个容器，数据依次输入，当容器未满k时，直接将数据插入。当容器已满时，需要将数据和容器中的最大值最比较，如果小于，则删除容器中的最大值并插入新数据，否则无操作。
这里的容器可以选择由红黑树实现的set或multiset（后者允许重复），插入删除为O(nlogk);所以总共的时间复杂度是O(nLogk)。
这样的算法不会修改原数组，且适合输入海量数据

测试用例：https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&tPage=2&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/
class Solution
{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> output;
        multiset<int, greater<int> > setInt; //创建一个带大于比较器的multiset,降序
        if (input.size() == 0 || k <= 0 || input.size() < k)
        {
            return output;
        }
        for (int i = 0; i < input.size(); i++)
        {
            if (setInt.size() < k)
            {
                //直接插入
                setInt.insert(input[i]);
            }
            else
            {
                if (*(setInt.begin()) > input[i]) //set中第一个是最大的
                {
                    setInt.erase(setInt.begin());
                    setInt.insert(input[i]);
                }
            }
        }
        //反向输出
        for (multiset<int>::reverse_iterator it = setInt.rbegin(); it != setInt.rend(); it++)
        {
            output.push_back(*it);
        }
        return output;
    }
};
int main()
{
    Solution solution;
    int a[] = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> input(a, a + 8);
    vector<int> output = solution.GetLeastNumbers_Solution(input, 10);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }

    return 0;
}