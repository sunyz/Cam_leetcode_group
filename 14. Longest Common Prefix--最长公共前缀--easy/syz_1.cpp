/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-05 00:25:25
 * @LastEditTime: 2019-04-05 01:29:24
 */

//  * @Description: 纯暴力，对每一位遍历一遍所有string，复杂度O(n*m)
//  * FIXME: 效果不好

// 执行用时 : 12 ms, 在Longest Common Prefix的C++提交中击败了16.93% 的用户
// 内存消耗 : 8.7 MB, 在Longest Common Prefix的C++提交中击败了0.90% 的用户


#include <algorithm>
#define MAX_INT 2147483647

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int cnt = strs.size();
        if (cnt == 0) return "";
        string ans = "";
        bool flag = true;
        int max = strs[0].size();
        if (max == 0) return "";
        for (int i=0; i < max; i++) {
            for (int j=1; j<cnt-1; j++) {
                if (i == 0 && strs[j] == "") {
                    return "";
                } else if  (strs[j].size() == i) {
                    return ans;
                } else if (strs[j][i] != strs[j-1][i]){
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                return ans;
            } else {
                ans += strs[0][i];
            }
        }
    }
};