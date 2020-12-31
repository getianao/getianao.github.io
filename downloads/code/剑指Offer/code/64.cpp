#include <iostream>
using namespace std;
/*
求1到n的和：
要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）

思路一：公式法(1+n)*n/2，使用了除法。

思路二：通过构造函数，一个静态类中保存了静态的当前加数和总数，构造函数中将加数加1，并加到总数中，还有一个清零函数。

思路三：通过继承和虚函数：A中有一个虚函数，B继承A，A和B存入一个数组下标是0和1，，B中的函数通过!!n来判断是否终止，!!n对不等于0的数为true，也就是1，可以递归的调用B的下标，!!n对等于0的数为false，也就是0，可以调用A的下标，A中终止递归，返回0。

思路四：或者将上面的数组换成函数指针的数组，就不需要通过虚函数和继承来实现了。

测试用例：https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/
class Temp
{
private:
    static int n;
    static int sum;

public:
    Temp()
    {
        n++;
        sum += n;
    }
    static void reset()
    {
        n = 0;
        sum = 0;
    }
    static int getSum()
    {
        return sum;
    }
};
//静态成员变量需要在类体外定义，类体里的只算是声明
int Temp::n = 0;
int Temp::sum = 0;

class Solution
{
public:
    int Sum_Solution(int n)
    {

        Temp::reset();
        Temp *t = new Temp[n];
        return Temp::getSum();
    }
};

int main()
{
    Solution solution;
    cout << solution.Sum_Solution(5) << endl;
    return 0;
}