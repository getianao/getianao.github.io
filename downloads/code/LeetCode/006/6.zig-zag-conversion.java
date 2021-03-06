/*
 * @lc app=leetcode id=6 lang=java
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (30.63%)
 * Total Accepted:    286.8K
 * Total Submissions: 936.2K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */
class Solution {
    public String convert(String s, int numRows) {
        String ans = "";
        int feature = 2 * numRows - 2;
        int addition1;
        int addition2;
        if (s.length() == 1 || numRows == 1) {
            return s;
        }
        for (int i = 0; i < numRows; i++) {
            int index = i;
            addition1 = feature - 2 * i;
            addition2 = feature - addition1;
            int add=-1;
            while (true) {
                if (index >= s.length()) {
                    break;
                }
                if (add != 0) {
                    ans += s.charAt(index);
                }
                
                if (add == -1 || add == addition2) {
                    add = addition1;
                } else {
                    add = addition2;
                }
                index += add;
            }
        }
        return ans;
    }
}
