/**
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
Example 1:
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
执行用时 : 20 ms, 在Longest Valid Parentheses的C++提交中击败了55.00% 的用户
内存消耗 : 9.4 MB, 在Longest Valid Parentheses的C++提交中击败了89.67% 的用户
要考虑特殊情况((((((()(())、()(()
首先，需要记录下第一个有效的左括号的位置
每层未匹配到的左括号位置也要压栈
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<short> stack;
        int res = 0;
        short start = 0;
        for (short i = 0; i < s.size(); i++) {
            // cout << i;
            if (s[i] == '(') {
                stack.push(i);
            } else {
                if (!stack.empty()) {
                    stack.pop();
                    res = (stack.empty()) ? max(res, i + 1 - start) : max(res, i - stack.top());
                    
                } else {
                    
                    start = i + 1;
                    // res = (res > i + 1 - start) ? res :(i + 1 - start);
                }
                
                // res = (res > i + 1 - start - stack.size()) ? res : (i + 1 - start - stack.size());
            }
        }
        return res;
    }
};
