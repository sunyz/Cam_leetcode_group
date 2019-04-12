/*
 * @Author: sunyz
 * @LastEditors: sunyz
 * @Date: 2019-04-12 22:12:16
 * @LastEditTime: 2019-04-12 22:57:20
 */

// * @Description: 标准的递归解法
// 但是特殊情况真的恶心啊。。。参见下面的算法描述
// 之前没有经过中间变量缓存，直接return，结果就会一直超时。。。
// 然后试一试的心态用中间变量缓存了一下，然后居然就过了。。。过了。。
// 所以如果有时候考虑临界变量的话，用中间结果缓存（强制类型和范围转换）可能会
// 避免奇奇怪怪的问题

// 执行用时 : 8 ms, 在Pow(x, n)的C++提交中击败了96.00% 的用户
// 内存消耗 : 8.1 MB, 在Pow(x, n)的C++提交中击败了98.47% 的用户

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        } else if (n == -1) {
            return 1/x;
        } else if (n % 2 == 0) {
            double temp = myPow(x, n/2);
            return temp * temp;
        } else {
            double temp = myPow(x, (n-1)/2);
            return x * temp * temp;
        }
    }
};

// 以下为在（0.0001， 1234567），（1.00001， 1234567）等极端例子中会超时的写法
// 即使加了临界判断也无效
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        } else if (n == -1) {
            return 1/x;
        } else if (n % 2 == 0) {
            return myPow(x, n/2) * myPow(x, n/2);
        } else {
            return x * myPow(x, (n-1)/2) * myPow(x, (n-1)/2);
        }
    }
};