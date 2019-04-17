/*
 * @Author: sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-17 22:47:15
 * @LastEditTime: 2019-04-17 22:48:17
 */


//  * @Description: 没啥可说的，暴力+双指针
//  * 
//  执行用时 : 72 ms, 在Reverse String的C++提交中击败了95.07% 的用户
// 内存消耗 : 15.1 MB, 在Reverse String的C++提交中击败了88.64% 的用户

class Solution {
public:
    void reverseString(vector<char>& s) {
        int right = s.size()-1;
        int left = 0;
        while (right > left) {
            swap(s[left], s[right]);
            right--;
            left++;
        }
    }
};