/**
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
执行用时 : 20 ms, 在3Sum Closest的C++提交中击败了24.19% 的用户
内存消耗 : 8.6 MB, 在3Sum Closest的C++提交中击败了0.33% 的用户
与15类似的思路，先排序
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // ios::sync_with_stdio(false);
        // sort it
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        int diff = abs(closest - target);
        // cout << "diff is " << diff << endl;
        
        for (int i = 0; i < nums.size(); i++) {
            
                int left = i+ 1;
                int right = nums.size() - 1;
                while (left < right) {
                    int sum = nums[i] + nums[left] + nums[right];
                    
                    if (abs(sum - target) < diff) {
                        diff = abs(sum - target);
                        closest = sum;
                        // cout << closest << endl;
                    }
                    if (sum < target)
                        left++;
                    else
                        right--;
                }

        }
        return closest;
    }
};
// 如果再加上diff == 0 时直接返回target会快几毫秒
