/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-22 00:24:06
 * @LastEditTime: 2019-04-22 00:48:46
 */

//  * @Description: 递推的思想，新建函数获取新一行，
//    每次传入前一行的结果，挺朴素的。。效果还行

// 执行用时 : 8 ms, 在Pascal's Triangle的C++提交中击败了95.84% 的用户
// 内存消耗 : 8.7 MB, 在Pascal's Triangle的C++提交中击败了46.84% 的用户

class Solution {
public:
    vector<int> get_row(vector<int> &last_row) {
        vector<int> this_row;
        this_row.push_back(1);
        for (int i=1; i<last_row.size(); i++) {
            int k = last_row[i] + last_row[i-1];
            this_row.push_back(k);
        }
        this_row.push_back(1);
        return this_row;
    }

    vector<vector<int>> generate(int numRows) {
        vector<int> eve_row;
        vector<vector<int>> ans;
        if (numRows >= 1) {
            eve_row.push_back(1);
            ans.push_back(eve_row);
            eve_row.clear();
        }
        for (int i=1; i<numRows; i++) {
            eve_row = get_row(ans[i-1]);
            ans.push_back(eve_row);
            eve_row.clear();                                                                                                                                                                                                                                                                                                                                                                     
        }
        return ans;
    }
};