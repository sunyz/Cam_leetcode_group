/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Date: 2019-05-11 00:14:04
 * @LastEditTime: 2019-05-11 01:03:52
 */


//  * @Description: 弱条件的动态规划
//  * DP[n] = {DP[n-1], DP[n-2], DP[n-1] + DP[n-2], 0}
//  * 主要是0的处理。。完全根据测试栗子来的。。。
//  * 特殊处理ifelse写的有点恶心。。

// 执行用时 : 8 ms, 在Decode Ways的C++提交中击败了96.49% 的用户
// 内存消耗 : 8.5 MB, 在Decode Ways的C++提交中击败了31.96% 的用户

class Solution {
public:
    int numDecodings(string s) {
        int cnt = s.size();
        int ans = 1;
        int n_1 = 1;  // n-1
        int n_2 = 1;  // n-2
        if (cnt == 1) return (s[0] != '0') ? 1 : 0;
        if (cnt >= 2) {
            if (s[0] == '0') {
                return 0;
            } else if (s[1] == '0' && s[0] > '2') {
                return 0;
            } else if (s.substr(0, 2) < "27" && s[1] != '0') {
                n_1 = 2;
                ans = n_1;
            } else {
                n_1 = 1;
                ans = n_1;
            } 
        } 
        for (int i = 2; i < cnt; i++) {
            if (s.substr(i-1, 2) == "00") return 0;
            if (s[i] == '0' && s[i-1] > '2') return 0;
            if ((s.substr(i-1, 2) < "27") && (s[i] != '0') && (s[i-1] != '0'))  {
                ans = n_1 + n_2;
                n_2 = n_1;
                n_1 = ans;
            } else if (s[i] == '0'){
                ans = n_2;
                n_2 = n_1;
                n_1 = ans; 
            } else {
                ans = n_1;
                n_2 = n_1;
            }
        }
        return ans;
    }
};