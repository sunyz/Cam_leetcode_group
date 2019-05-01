/*
 * @Author: sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-05-01 15:22:18
 * @LastEditTime: 2019-05-01 16:58:13
 */

//  * @Description:我真菜。。一个简单题做崩了好久。。
//  * 最开始思路是，对每一个数，一直往后找，找其能得到的最大和，然后更新ans
//  * 然后反应过来我蠢了。。。O(n)是完全可以的
//  * 就是如果第n个之前的和都大，直接从第n个开始新的序列的检索
//  * 并且注意如果是第n个负数的情况下，比tmp大但是不一定比ans大，所以ans要取max
//  * 但是tmp会更新
//  * 所以开始的式子就可以简化成最后的样子
//  * 其实直接用动态规划想更简单
//  * 以下摘自评论区
//  * dp 方程: dp[i] = max(nums[i] + dp[i - 1], nums[i])
//  * 求解: max(dp[0]...dp[n]) 状态可以压缩下，只需要记录前一个 dp 值即可
// FIXME: 题目提示中的分治法没有思路

// 执行用时 : 12 ms, 在Maximum Subarray的C++提交中击败了97.82% 的用户
// 内存消耗 : 9.4 MB, 在Maximum Subarray的C++提交中击败了75.44% 的用户

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int tmp = nums[0];
        for (int i=1; i<nums.size(); i++) {
            tmp += nums[i];
            // 下面是简化版
            tmp = max(nums[i], tmp);
            ans = max(ans, tmp);
            // 下面是原始思路版
            // if (nums[i] > tmp) {
            //     ans = max(nums[i], ans);
            //     tmp = nums[i];
            // } else {
            //     ans = max(ans, tmp);
            // }   
        }
        return ans;
    }
};