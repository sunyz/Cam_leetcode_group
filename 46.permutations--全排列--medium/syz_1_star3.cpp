/*
 * @Author: sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-16 16:25:29
 * @LastEditTime: 2019-04-16 17:51:26
 */

//  * @Description: 用的是标准的递归的思想
//  * 具体解释请参考   https://blog.csdn.net/lemon_tree12138/article/details/50986990
//  * 同样的思路，解释的更加清楚

// 执行用时 : 32 ms, 在Permutations的C++提交中击败了44.97% 的用户
// 内存消耗 : 9.2 MB, 在Permutations的C++提交中击败了78.14% 的用户

class Solution {
public:
    void sub_permute(vector<int> &nums, vector<int>& tmp, int start, vector<vector<int>>& ans) {
        if (nums.size() == start+1) {
             tmp.push_back(nums[start]);
             ans.push_back(tmp);
             tmp.pop_back();
        } else {
            for (int i = start; i< nums.size(); i++) {
                tmp.push_back(nums[i]);
                int a = nums[i];
                nums[i] = nums[start];
                nums[start] = a;
                sub_permute(nums, tmp, start+1, ans);
                tmp.pop_back();
                nums[start] = nums[i];
                nums[i] = a;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() == 0) return ans;
        vector<int> tmp;
        if (nums.size() == 1) {
            tmp.push_back(nums[0]);
            ans.push_back(tmp);
            return ans;
        }
        for (int i=0; i<nums.size(); i++) {
            int a = nums[i];
            nums[i] = nums[0];
            nums[0] = a;
            tmp.push_back(nums[0]);
            sub_permute(nums, tmp,1,ans);
            //ans.push_back(tmp);
            tmp.clear();
            nums[0] = nums[i];
            nums[i] =a;
        }

        
        return ans;
    }
};