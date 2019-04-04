/**
 *
 Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string ""
解法是暴力求解，感觉跟答案给的差不多，不知道为什么效果挺差的。
执行用时 : 16 ms, 在Longest Common Prefix的C++提交中击败了11.93% 的用户
内存消耗 : 8.6 MB, 在Longest Common Prefix的C++提交中击败了0.90% 的用户
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int j = 0;
        char ch;
        if (strs.size() > 0)
            ch = strs[0][0];
        else
            return "";
        bool jumpout = false;
        while (true) {
            for (int i = 0; i < strs.size(); i++) {
                if (strs[i].size() <= j || strs[i][j] != ch) {
                    jumpout = true;
                    break;
                }
            }
            if (jumpout)
                break;
            res += ch;
            j++;
            ch = strs[0][j];
        }
        return res;
    }
};
