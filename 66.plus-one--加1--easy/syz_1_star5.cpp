/*
 * @Author: sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-29 23:27:58
 * @LastEditTime: 2019-04-29 23:28:53
 */

//  * @Description: 基本就是暴力的加
//  * 由于只是加1，所以进位为0时前面的位可以直接copy
//  * 这里用的是insert函数

// 执行用时 : 8 ms, 在Plus One的C++提交中击败了96.65% 的用户
// 内存消耗 : 8.8 MB, 在Plus One的C++提交中击败了5.45% 的用户

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int jinwei= 0;
        int cnt = digits.size();
        int i = 0;
        for (i=0; i<cnt; i++) {
            ans.insert(ans.begin(), (digits[cnt - i -1] + (i==0) + jinwei)%10);
            jinwei = (digits[cnt - i -1] + (i==0) + jinwei)/10;
            if (jinwei == 0) {
                i++;
               for (i; i<cnt; i++) {
                    ans.insert(ans.begin(), digits[cnt - i - 1]);
                }
                return ans;
            }
                
        }
        if(jinwei) {
            ans.insert(ans.begin(), 1);
        }
        return ans;
    }
};