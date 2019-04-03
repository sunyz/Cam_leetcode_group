/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-04 00:28:21
 * @LastEditTime: 2019-04-04 01:57:11
 */

//  * @Description: 如果用字符串真的是秒出结果的题目。。。强行要求用运算，
//  * 不过结果还不错
//  * 思路：
//  * - 特殊情况直接返回，比如负数和10以内
//  * - 用log10（x）+1 直接获得位数（！！！我蠢死了，开始忘记取floor了，检查了好久。。。）
//  * - 如果是对半，前后同时操作的话，掐头去尾，则在掐头时会有大坑在里面，即第二位是0等，导致
//  *    掐头多掐了，所以应该在末尾再判断是否是0来补掉
//  * -  NOTE: 使用log10前要注意x是否已经是0！！！
//  * - 更新cnt


// 执行用时 : 52 ms, 在Palindrome Number的C++提交中击败了99.58% 的用户
// 内存消耗 : 8.4 MB, 在Palindrome Number的C++提交中击败了93.02% 的用户

#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {
        if ( x < 0 ) {
            return false;
        } else if (x < 10) { // single num must be palindrome
            return true;
        }
        if (x % 10 == 0) {  // cannot end with ZERO
            return false;
        } else {
            int cnt = floor(log10(x))+1; // get num in x
            while (cnt/2 > 0) {
                int left = int(pow(10, cnt-1));
                if ( (x / left) != (x % 10)){
                    return false;
                } else {
                    x %= left;
                    x /= 10;
                    cnt -= 2;
                    if (x == 0) {
                      return true;
                    }
                    int tmp = floor(log10(x)) + 1;
                    int zero_num = cnt - tmp;
                    if (zero_num > 0) {
                        int right = int(pow(10, zero_num));
                        if (x % right != 0) { //not 0 in end
                            return false;
                        } else {
                            x /= right;
                        }
                        cnt = tmp - zero_num;
                    }  
                }
            }
            return true;
        }
    }
};