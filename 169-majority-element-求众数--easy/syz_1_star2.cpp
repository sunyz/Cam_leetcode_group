/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Date: 2019-05-06 01:09:21
 * @LastEditTime: 2019-05-06 01:14:02
 */

 * @Description: 自己做的没有什么好的想法
 * 所以最后暴力排序之后取中间值了
 * 神仙解法参见同时提交的recommend

执行用时 : 40 ms, 在Majority Element的C++提交中击败了56.91% 的用户
内存消耗 : 11.1 MB, 在Majority Element的C++提交中击败了64.16% 的用户

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      return  nums[nums.size()/2];
    }
};