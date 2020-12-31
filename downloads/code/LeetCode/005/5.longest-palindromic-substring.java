/*
 * @lc app=leetcode id=5 lang=java
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (26.53%)
 * Total Accepted:    478K
 * Total Submissions: 1.8M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
class Solution {
    public String longestPalindrome(String s) {
        String ans = "";// 初始化为空
        for (int start = 0; start < s.length(); start++) {
            String charInStr = s.substring(start, start + 1);// 起始或结束字符
            String inStr= s.substring(start);
            String str = loopJudge(charInStr, inStr);
            if (str == null) {
                continue;
            }
            if (str.length() >= ans.length()) {
                ans = str;
            }
        }
        return ans;
    }

    public String loopJudge(String charInStr, String s) {
        int end = s.lastIndexOf(charInStr.substring(1));//跳过自身
        while (true) {
            if (end == -1) {
                // 此时不存在回文,返回null
                break;
            } else {
                String str = (s + " ").substring(0, end + 1);// 切割得到待判断的字符串
                str = str.substring(0, str.length() - 1);
                if (isPalindrome(str) == true) {
                    return str;

                } else {
                    String str2 = loopJudge(charInStr, str.substring(0, str.length() - 1));
                    if (str2 != null) {
                        return str2;
                    } else {
                        return null;
                    }
                }
            }
        }
        return null;
    }

    public boolean isPalindrome(String s) {
        for (int i = 0; i <= s.length() / 2; i++) {
            if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }
}
