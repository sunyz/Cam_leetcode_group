/*
 * @Author: sunyz
 * @Date: 2019-05-21 23:01:24
 * @LastEditors: sunyz
 * @LastEditTime: 2019-05-21 23:17:35
 */


//  * @Description: 数学题
//  * 公式： 1+3+5+7+9+…+(2n-1)=n^2

// 执行用时 : 4 ms, 在Valid Perfect Square的C++提交中击败了96.62% 的用户
// 内存消耗 : 8.3 MB, 在Valid Perfect Square的C++提交中击败了5.35% 的用户

class Solution {
public:
    bool isPerfectSquare(int num) {
        long k=1;
        long total = k;
        while(num > total) {
            k += 2;
            total += k;
        }
        return (total == num);

    }
};