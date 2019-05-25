/*
 * @Author: sunyz
 * @Date: 2019-05-25 22:56:38
 * @LastEditors: sunyz
 * @LastEditTime: 2019-05-25 23:02:19
 */


//  * @Description: 之前某个题，在pair中找单独的某个的变形
//  * 区别是从int变成了char
//  * 所以做 异或  之后剩下的就是多余的那个
//  * 我的思路是拼接了
//  * 然后看了一下评论可以不用拼接，直接分别做 异或 的和就行了

// 执行用时 : 8 ms, 在Find the Difference的C++提交中击败了94.42% 的用户
// 内存消耗 : 9.3 MB, 在Find the Difference的C++提交中击败了23.48% 的用户

class Solution {
public:
    char findTheDifference(string s, string t) {
        s = s + t;
        char ans = 0;
        for (int i=0; i<s.size(); i++) {
            ans ^= s[i];
        }
        return ans;
    }
};