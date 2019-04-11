/**
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
注意：
答案中不可以包含重复的四元组。
执行用时 : 88 ms, 在4Sum的C++提交中击败了47.44% 的用户
内存消耗 : 9.1 MB, 在4Sum的C++提交中击败了0.95% 的用户
思路和3Sum差不多，在避免重复上也要下功夫
还可以改进的地方有：申请变量表示nums.size(),i后四个数大于target的剪枝，以及各个地方的剪枝。
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i, j, left, right;
        vector<vector<int>> res;
        if (nums.size() < 4) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && (nums[i] == nums[i - 1]))
                continue;
            for (j = i + 1; j <nums.size() - 2; j++) {
                if (nums[j] == nums[j-1] && (j - 1 != i))
                    continue;
                left = j + 1;
                right = nums.size() - 1;
                while(left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        auto a = vector<int>({nums[i], nums[j], nums[left], nums[right]});
                        
                        res.push_back(a);
                        left++;
                        right--;
                        while((left < nums.size() - 1) && nums[left-1] == nums[left]) {
                            left++;
                        }
                        
                    } else if (sum < target) {
                        left++;
                    } else if (sum > target) {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
