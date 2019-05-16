/*
 * @Author: sunyz
 * @Date: 2019-05-16 20:41:45
 * @LastEditors: sunyz
 * @LastEditTime: 2019-05-16 23:53:23
 */

//  * @Description: 我的想法就很朴素了。。
//  * 遍历，如果找到能形成回文串中间的“核”，
//  * 则从“核”开始向两边找，并记录长度和ans
FIXME: 需要看更加高效的解法

// 执行用时 : 32 ms, 在Longest Palindromic Substring的C++提交中击败了80.05% 的用户
// 内存消耗 : 12.6 MB, 在Longest Palindromic Substring的C++提交中击败了53.51% 的用户

class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 1;
        string ans = s.substr(0,1);
        int cnt = s.size();
        int current_len = 1;
        for (int i=0; i<cnt; i++) {
            current_len = 1;
            if (i+1 < cnt && s[i] == s[i+1]) {
                current_len = 2;
                int left = i - 1;
                int right = i + 2;
                while (left > -1 && right < cnt) {
                    if (s[left] == s[right]) {
                        current_len += 2;
                        left --;
                        right ++;
                    } else {
                        break;
                    }
                }
                if (current_len > max_len) {
                    max_len = current_len;
                    ans = s.substr(left + 1, max_len);
                }
            }
            if (i+1 < cnt && i-1 > -1 && s[i-1] == s[i+1]) {
                current_len = 3;
                int left = i - 2;
                int right = i + 2;
                while (left > -1 && right < cnt) {
                    if (s[left] == s[right]) {
                        current_len += 2;
                        left --;
                        right ++;
                    } else {
                        break;
                    }
                }
                if (current_len > max_len) {
                    max_len = current_len;
                    ans = s.substr(left + 1, max_len);
                }
            }
        }
        return ans;
    }
};