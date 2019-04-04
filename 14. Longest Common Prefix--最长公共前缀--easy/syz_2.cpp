/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-05 01:29:36
 * @LastEditTime: 2019-04-05 01:33:03
 */

// * @Description: 低效方法之二
//   - 首先用了排序，算法库的sort函数
//   - 然后比较第一个和最后一个
//   FIXME: 效果不好
//   NOTE: 试过了提交历史中标注时间是4ms的例子，结果也是这个时间，迷

// 执行用时 : 12 ms, 在Longest Common Prefix的C++提交中击败了16.93% 的用户
// 内存消耗 : 8.8 MB, 在Longest Common Prefix的C++提交中击败了0.90% 的用户

#include <algorithm>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int cnt = strs.size();
        if (cnt == 0) {
          return "";
        }
        std::sort(strs.begin(), strs.end());
        if (strs[0] == "") {
            return "";
        } else {
            string ans = "";
            string s1 = strs[0];
            string s2 = strs[cnt-1];
            int max_length = s1.length() > s2.length() ? s2.length() :s1.length();
            for (int i = 0; i < max_length ;i++) {
                if (s1[i] == s2[i]) {
                    ans.assign(s1, 0, i+1);
                } else {
                  return ans;
                }
            }
            return ans;
        }
    }
};