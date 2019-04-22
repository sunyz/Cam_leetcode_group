/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-22 23:50:35
 * @LastEditTime: 2019-04-23 00:08:47
 */

//  * @Description: 很正常的思路
//  * 利用了isalnum函数，判断是否是字母或者数字
//  * 利用了tolower函数，统一小写
//  * 双指针的基本思路


// 执行用时 : 16 ms, 在Valid Palindrome的C++提交中击败了95.06% 的用户
// 内存消耗 : 9.1 MB, 在Valid Palindrome的C++提交中击败了67.38% 的用户

class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int right = s.size()-1;
        while(right > left) {
            if (!isalnum(s[left])) {
                left ++;
                continue;
            } 
            if (!isalnum(s[right])) {
                right --;
                continue;
            }
            if (s[left] == s[right] || tolower(s[left]) == tolower(s[right])) {
                right --;
                left ++;
            } else {
                return false;
            }
        }
        return true;
    }
};