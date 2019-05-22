/*
 * @Author: sunyz
 * @Date: 2019-05-22 23:59:11
 * @LastEditors: sunyz
 * @LastEditTime: 2019-05-23 00:00:47
 */


//  * @Description: 标准二分法
//  * 注意一下坑就是中间数
//  * 不能用（a+b）/2
//  * 应该用 a+(b-a)/2 
//  * 虽然数学意义一样
//  * 但是后一种不会溢出

// 执行用时 : 0 ms, 在Guess Number Higher or Lower的C++提交中击败了100.00% 的用户
// 内存消耗 : 8.2 MB, 在Guess Number Higher or Lower的C++提交中击败了30.07% 的用户


// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        unsigned long tmp = left + (right - left) / 2;;
        while (guess(tmp) != 0) {
            if (guess(tmp) == -1) {
                right = tmp;
                tmp = left + (right - left) / 2;
            } else if (guess(tmp) == 1) {
                if (left == tmp) {
                    left = tmp + 1;
                } else {
                    left = tmp;
                }  
                tmp = left + (right - left) / 2;
            }
        }
        return tmp;
    }
};