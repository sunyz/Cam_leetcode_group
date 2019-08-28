/*
 * @Author: sunyz
 * @Date: 2019-08-28 23:46:52
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @LastEditTime: 2019-08-29 01:01:45
 */


// 开始真实的刷，看3分钟，想5分钟，看解析，然后复现即可

// 只选取一个有效可行的方案即可
// 思路
// 标签：数组遍历
// 首先对数组进行排序，排序后固定一个数 nums[i]nums[i]，再使用左右指针指向 nums[i]nums[i]后面的两端，数字分别为 nums[L]nums[L] 和 nums[R]nums[R]，计算三个数的和 sumsum 判断是否满足为 00，满足则添加进结果集
// 如果 nums[i]nums[i]大于 00，则三数之和必然无法等于 00，结束循环
// 如果 nums[i]nums[i] == nums[i-1]nums[i−1]，则说明该数字重复，会导致结果重复，所以应该跳过
// 当 sumsum == 00 时，nums[L]nums[L] == nums[L+1]nums[L+1] 则会导致结果重复，应该跳过，L++L++
// 当 sumsum == 00 时，nums[R]nums[R] == nums[R-1]nums[R−1] 则会导致结果重复，应该跳过，R--R−−
// 时间复杂度：O(n^2)O(n
// 2
//  )，nn 为数组长度

// 作者：guanpengchn
// 链接：https://leetcode-cn.com/problems/3sum/solution/hua-jie-suan-fa-15-san-shu-zhi-he-by-guanpengchn/


// 3 close类似，直接是动态更新差值，并记录最小


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if ((target = nums[i]) > 0) break;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] + target < 0) ++l;
                else if (nums[l] + nums[r] + target > 0) --r;
                else {
                    ans.push_back({target, nums[l], nums[r]});
                    ++l, --r;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                }
            }
        }
        return ans;
    }
};