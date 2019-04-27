/**
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例:
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:
如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

执行用时 : 12 ms, 在Maximum Subarray的C++提交中击败了97.76% 的用户
内存消耗 : 9.3 MB, 在Maximum Subarray的C++提交中击败了76.90% 的用户
看了评论区才知道原来可以这么解。
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // construct an array, array[i] indicates the largest
        // sub array which ends at i
        vector<int> array(nums.size(), 0);
        array[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            array[i] = max(array[i - 1] + nums[i], nums[i]);
            if (array[i] > res)
                res = array[i];
        }
        return res;
    }
};
