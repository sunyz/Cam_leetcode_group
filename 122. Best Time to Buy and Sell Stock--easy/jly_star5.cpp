/**
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
Example 1:
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
          
执行用时 : 12 ms, 在Best Time to Buy and Sell Stock II的C++提交中击败了95.09% 的用户
内存消耗 : 9.6 MB, 在Best Time to Buy and Sell Stock II的C++提交中击败了14.24% 的用户
这题只要想清楚了逻辑，还是挺明显的。改买还是卖只要根据走势决定就行。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        bool baught = false;
        short buy;
        short len = prices.size();
        for (short i = 0; i < len; i++) {
            if (baught) {
                if ((i == len - 1) || prices[i+1] < prices[i]) {
                    baught = false;
                    res += prices[i] - buy;
                }
            } else {
                if ((i != len - 1 )&& (prices[i+1] > prices[i])) {
                    baught = true;
                    buy = prices[i];
                }
            }
        }
        return res;
        
    }
};
