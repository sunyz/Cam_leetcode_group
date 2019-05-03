/*
 * @Author: sunyz
 * @LastEditors: sunyz
 * @Date: 2019-05-04 00:05:04
 * @LastEditTime: 2019-05-04 00:06:25
 */

 * @Description: 最暴力了。。
 * vector转set
 * 所以效果一般
 * FIXME: 之后重做

执行用时 : 68 ms, 在Contains Duplicate的C++提交中击败了52.26% 的用户
内存消耗 : 18.1 MB, 在Contains Duplicate的C++提交中击败了5.09% 的用户

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        return !(st.size() == nums.size());
    }
};