/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Date: 2019-05-09 00:21:53
 * @LastEditTime: 2019-05-09 00:53:57
 */

//  * @Description: 本来只是想试试的暴力方法居然ok了。。。。
//  * 思路就是把问题翻译成降序排序后输出
//  * 用sort函数，但是要自定义比较函数
//  * 同时需要注意多个0的问题，所以在int转string会求和，如果是0则直接返回"0"

// 执行用时 : 16 ms, 在Largest Number的C++提交中击败了93.90% 的用户
// 内存消耗 : 9.3 MB, 在Largest Number的C++提交中击败了74.89% 的用户

class Solution {
public:
    static bool Less(const string& s1, const string& s2)
    {
        return s1 + s2 > s2 + s1; // 为了降序
    }

    string largestNumber(vector<int>& nums) {
        int cnt = nums.size();
        if (cnt == 0) return "";
        string ans;
        vector<string> lala;
        int zero_cnt = 0;
        for (int i=0; i<cnt; i++) {
            if (zero_cnt == 0) zero_cnt += nums[i];
            lala.push_back(to_string(nums[i]));
        }
        if (zero_cnt == 0) return "0";
        sort(lala.begin(), lala.end(),Less);
        for (int i=0; i<cnt; i++) {
            ans += lala[i];
        }
        return ans;

    }
};
