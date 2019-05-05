这道题的标准最优解法(O(N)复杂度)是摩尔投票算法

解析参考这个知乎问答：
https://www.zhihu.com/question/49973163

执行用时 : 24 ms, 在Majority Element的C++提交中击败了97.83% 的用户
内存消耗 : 11 MB, 在Majority Element的C++提交中击败了87.66% 的用户


class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int major, counts = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (counts == 0) {
                major = nums[i];
                counts = 1;
            }
            else counts += (nums[i] == major) ? 1 : -1;
        }
        return major;
    }
};