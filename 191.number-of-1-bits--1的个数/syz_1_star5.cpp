/*
 * @Author: sunyz
 * @Date: 2019-05-13 00:05:26
 * @LastEditors: sunyz
 * @LastEditTime: 2019-05-13 00:06:26
 */

//  * @Description: 就是基本位运算。。
 
// 执行用时 : 8 ms, 在Number of 1 Bits的C++提交中击败了97.02% 的用户
// 内存消耗 : 8.1 MB, 在Number of 1 Bits的C++提交中击败了31.67% 的用户

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n > 0) {
            ans += (n&1);
            n = n >> 1;
        }
        return ans;
    }
};