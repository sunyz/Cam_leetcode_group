/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Date: 2019-05-10 02:07:45
 * @LastEditTime: 2019-05-10 02:54:47
 */

//  * @Description: 其实还是很暴力了。。
//  * 分情况讨论
//  * 遇到负数就做标记，两次标记对消一次，并且补充乘法一次
//  * 为了应对奇数个负数，从左到右和从右到左各做一次
//  * 0的话就截断
//  * 根据测试用例调了无数次，心塞。。。


// 执行用时 : 12 ms, 在Maximum Product Subarray的C++提交中击败了95.37% 的用户
// 内存消耗 : 9 MB, 在Maximum Product Subarray的C++提交中击败了64.79% 的用户


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int fushu_flag = -1;
        int ans1 = nums[0];
        int ans2 = nums[nums.size()-1];
        int cur = 1;
        int left =1;
        for (int i=0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                cur *= nums[i];
                ans1 = max(ans1, cur);
            } else if (nums[i] == 0) {
                fushu_flag = -1;
                ans1 = max(ans1,0);
                cur = 1;
            } else {
                if (fushu_flag > -1) {
                    cur = left * nums[fushu_flag] * cur *nums[i];
                    ans1 = max(cur, ans1);
                    fushu_flag = -1;
                } else {
                    fushu_flag = i;
                    left = cur;
                    cur = 1;
                }
            }
        }
        cur = 1;
        left =1;
        fushu_flag = -1;
        for (int i=nums.size()-1; i>=0 ; i--) {
            if (nums[i] > 0) {
                cur *= nums[i];
                ans2 = max(ans2, cur);
            } else if (nums[i] == 0) {
                fushu_flag = -1;
                cur = 1;
                ans2 = max(ans2,0);
            } else {
                if (fushu_flag > -1) {
                    cur = left * nums[fushu_flag] * cur *nums[i];
                    ans2 = max(cur, ans2);
                    fushu_flag = -1;
                } else {  
                    fushu_flag = i;
                    left = cur;
                    cur = 1;
                }
            }
        }
        return max(ans1, ans2);
    }
};