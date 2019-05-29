/*
 * @Author: sunyz
 * @Date: 2019-05-29 23:29:50
 * @LastEditors: sunyz
 * @LastEditTime: 2019-05-30 00:29:01
 */

 * @Description: 排序后遍历
 * FIXME: 之后重做

// 执行用时 : 184 ms, 在Find All Numbers Disappeared in an Array的C++提交中击败了50.00% 的用户
// 内存消耗 : 15.1 MB, 在Find All Numbers Disappeared in an Array的C++提交中击败了21.91% 的用户

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() == 0) return ans;
        sort(nums.begin(), nums.end());
        if (nums[0] > 1) {
            for (int i=1; i<nums[0]; i++) {
                ans.push_back(i);
            }
        }
        for (int i=1; i < nums.size(); i++) {
            if (nums[i] > (nums[i-1]+1)) {
               for (int j=nums[i-1]+1; j<nums[i]; j++) {
                ans.push_back(j);
                }
            }
        }
        if (nums[nums.size()-1] < nums.size()) {
            for (int i=nums[nums.size()-1]+1; i<=nums.size(); i++) {
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};