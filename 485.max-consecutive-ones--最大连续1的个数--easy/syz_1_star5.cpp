/*
 * @Author: sunyz
 * @Date: 2019-06-01 00:19:31
 * @LastEditors: sunyz
 * @LastEditTime: 2019-06-01 00:20:17
 */

 * @Description: emmm就是暴力遍历统计。。

执行用时 : 40 ms, 在Max Consecutive Ones的C++提交中击败了97.01% 的用户
内存消耗 : 11.7 MB, 在Max Consecutive Ones的C++提交中击败了70.24% 的用户

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur = 0;
        int ans = 0;
        int cnt = nums.size();
        for (int i=0; i < cnt; i++) {
            cur += nums[i];
            if (nums[i] == 0) {
                ans = max(ans, cur);
                cur = 0;
            }     
        }
        ans = max(ans, cur);
        return ans;
    }
};