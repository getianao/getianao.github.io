
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/*
https://leetcode-cn.com/problems/reverse-integer/

solution 1:
read the given integer as string, remove the sign and reverse the string，trim the zero which is at the top
of the string, in the end add the negative sign at the top of string.

note:
the point should pay attention is size of yhe value.
*/
class Solution
{
public:
    int reverse(int x)
    {
        bool isNegative = false;
        string str = to_string(x);
        // when the length of integer is 1, return the integer directly
        if (str.length() > 1)
        {
            if (str[0] == '-')
            {
                isNegative = true;
                str = str.substr(1, str.length());
            }
            str = reverseString(str);
            str = trimString(str);
            if (isNegative)
            {
                str = "-" + str;
            }
        }
        // create long type value to stroe signed value
        long ret = 0;
        istringstream(str) >> ret;
        //judge the result is 32-bit signed integer
        int max = 0x7fffffff, min = 0x80000000; 
        return ret > max || ret < min ? 0 : ret;
    }

private:
    string reverseString(string str)
    {
        char temp;
        for (int i = 0; i < str.length() / 2; i++)
        {
            temp = str[i];
            str[i] = str[str.length() - i - 1];
            str[str.length() - i - 1] = temp;
        }
        return str;
    }
    string trimString(string str)
    {
        int index = 0;
        while (str[index] == '0')
        {
            index++;
        }
        return str.substr(index, str.length());
    }
};

int main()
{
    Solution solution;
    int x;
    cin >> x;
    cout << solution.reverse(x) << endl;
    return 0;
}