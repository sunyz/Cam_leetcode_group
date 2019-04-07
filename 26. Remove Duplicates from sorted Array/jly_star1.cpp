/**
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
记录删除了多少个数字，删除后将后面的数字向前挪
执行用时 : 952 ms, 在Remove Duplicates from Sorted Array的C++提交中击败了0.98% 的用户
内存消耗 : 9.8 MB, 在Remove Duplicates from Sorted Array的C++提交中击败了0.95% 的用户
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size())
            return 0;
        int rmnum = 0;
        for (int i = 0; i < nums.size() - 1 - rmnum;) {
            if (nums[i+1] == nums[i]) {
                for (int j = i + 1; j < nums.size() - 1 - rmnum; j++) {
                    nums[j] = nums[j+1];
                }
                rmnum++;
            } else {
                i++;
            }
        }
        return nums.size() - rmnum;
    }
};
