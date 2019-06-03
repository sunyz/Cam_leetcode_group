/*
 * @Author: sunyz
 * @Date: 2019-06-04 00:56:30
 * @LastEditors: sunyz
 * @LastEditTime: 2019-06-04 00:57:28
 */

//  * @Description: 统计大写字母的个数

// 执行用时 : 4 ms, 在Detect Capital的C++提交中击败了97.50% 的用户
// 内存消耗 : 8.2 MB, 在Detect Capital的C++提交中击败了82.03% 的用户

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for (int i=0; i<word.size(); i++) {
            if (isupper(word[i])) {
                cnt++;
            }
        }
        if (cnt == 0 || cnt == word.size()) {
            return true;
        } else if (cnt == 1 && isupper(word[0])) {
            return true;
        }
        return false;
    }
};