/**
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
你可以假设数组中不存在重复的元素。
你的算法时间复杂度必须是 O(log n) 级别。
示例 1:
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:
输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1

执行用时 : 8 ms, 在Search in Rotated Sorted Array的C++提交中击败了96.98% 的用户
内存消耗 : 8.9 MB, 在Search in Rotated Sorted Array的C++提交中击败了71.85% 的用户
吐槽一下这个性能真不稳定，一会90%+  一会80%+

题目要求算法复杂度logN ，那么二分就对了
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if (right < 0)
            return -1;
        int mid = (left + right) / 2;
        if (nums[left] < target) {
            cout << nums[left] << endl;
            while (nums[left] > nums[right]) {
                if (nums[mid] > nums[left]) {
                    if (nums[mid] > target)
                        return split_search(nums, left, mid, target);
                    else if (nums[mid] < target) {
                        left = mid;
                        mid = (left + right) / 2;
                    } else {
                        return mid;
                    }
                } else {
                    right = mid;
                    mid = (left + right) / 2;
                }
            }
            // cout << "here" << endl;
            return split_search(nums, left, right, target);
        } else if (nums[right] > target) {
            // at right part
            // cout << "should";
            while (nums[left] > nums[right]) {
                if (nums[mid] < nums[right]) {
                    if (nums[mid] > target) {
                        right = mid;
                        mid = (left + right) / 2;
                    } else if (nums[mid] < target) {
                        return split_search(nums, mid, right, target);
                    } else {
                        return mid;
                    }
                } else {
                    left = mid + 1;
                    mid = (left + right) / 2;
                }
            }
            return split_search(nums, left, right, target);
            
        } else if (nums[left] == target) {
            return 0;
        } else if (nums[right] == target) {
            return right;
        } else {
            return -1;
        }
    }
    int split_search(vector<int>& nums, int left, int right, int target) {
        int mid = (left + right) / 2;
        if (left <= right) {
            if (target > nums[mid])
                return split_search(nums, mid + 1, right, target);
            else if (target < nums[mid])
                return split_search(nums, left, mid - 1, target);
            else
                return mid;
        } else {
            return -1;
        }
        
    }
};
