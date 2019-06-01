/*
 * @Author: sunyz
 * @Date: 2019-06-01 23:24:09
 * @LastEditors: sunyz
 * @LastEditTime: 2019-06-01 23:24:46
 */

 * @Description: 数学题

执行用时 : 8 ms, 在Arranging Coins的C++提交中击败了99.06% 的用户
内存消耗 : 8.3 MB, 在Arranging Coins的C++提交中击败了73.33% 的用户

#include <cmath>
class Solution {
public:
    int arrangeCoins(int n) {
        return (int)floor(sqrt(2.0 * n + 0.25) - 0.5);
    }
};