/*
 * @Author: sunyz
 * @Date: 2019-05-19 17:53:11
 * @LastEditors: sunyz
 * @LastEditTime: 2019-05-19 23:25:21
 */

//  * @Description: 公式真的是简单暴力。。
//  * 如果不用公式的话也可以动态规划
//  * 递归不递归都行
//  * 既然是特殊例子了那就还是公式最优解好了


// 执行用时 : 8 ms, 在Gray Code的C++提交中击败了96.59% 的用户
// 内存消耗 : 8.4 MB, 在Gray Code的C++提交中击败了81.36% 的用户

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for (int i=0; i < pow(2, n); i++) {
            ans.push_back((i >> 1) ^ i); // 公式
        }
        return ans;
    }
};