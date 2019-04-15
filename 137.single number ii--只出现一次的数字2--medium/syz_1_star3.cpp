/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-16 01:48:55
 * @LastEditTime: 2019-04-16 01:50:36
 */

//  * @Description:和ID-136思路一样，排序然后遍历
//  * 还是直接看下面的大佬做法吧orzz
 
//  执行用时 : 20 ms, 在Single Number II的C++提交中击败了70.62% 的用户
// 内存消耗 : 9.6 MB, 在Single Number II的C++提交中击败了51.77% 的用户

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for (int i=0;i < nums.size()-1; i+=3) {
            if (nums[i] != nums[i+1]) {
                return nums[i];
            }
        } 
        return nums[nums.size()-1];
    }
};