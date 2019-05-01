/*
 * @Author: sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-05-01 17:02:35
 * @LastEditTime: 2019-05-01 17:34:32
 */

//  * @Description: 
// dp: a[i] =  a[i-1] + 1 + a[i-2]
// a[1] = 1
// a[2] = 2
// 就是斐波那契数列的第二位开始
// 注意！！！千万不要用递归，会超时！！

// 执行用时 : 4 ms, 在Climbing Stairs的C++提交中击败了97.73% 的用户
// 内存消耗 : 8.4 MB, 在Climbing Stairs的C++提交中击败了50.66% 的用户


class Solution {
public:
    int climbStairs(int n) {
        int ans;
        if (n == 1) {
            ans = 1;
        } else if (n == 2) {
            ans = 2;
        } else {
            int a1 = 1;
            int a2 = 2;
            for (int i=3; i<=n; i++) {
                ans = a1 + a2;
                a1 = a2;
                a2 = ans;
            }
        }
        return ans;
    }
};