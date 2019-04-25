/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-26 00:04:06
 * @LastEditTime: 2019-04-26 01:38:36
 */

 * @Description: 标准的动态规划
 * 我也是脑抽了开始居然想的是双指针
 * 递推关系就是两个：
 * 前n天的最低价等于 min(前n-1天的最低价， 第n天价格)
 * 前n天的最大收益等于 max(前n-1天的最大收益，第n天价格 - 前n天最低价)
 * 然后从0开始递推就好了


执行用时 : 12 ms, 在Best Time to Buy and Sell Stock的C++提交中击败了96.78% 的用户
内存消耗 : 9.3 MB, 在Best Time to Buy and Sell Stock的C++提交中击败了92.98% 的用户

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cnt = prices.size();
        int min_p = 1000000, max_p = 0;
        if (cnt < 2) {
            return 0;
        } else {
           for (int i=0; i<cnt; i++) {
            min_p = min(min_p, prices[i]);
            max_p = max(max_p, prices[i] - min_p);
           }
           
        }
        return max_p;

    }
};