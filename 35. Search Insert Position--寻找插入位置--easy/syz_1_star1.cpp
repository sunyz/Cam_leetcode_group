/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-05 23:32:53
 * @LastEditTime: 2019-04-06 01:09:23
 */

// * @Description: 一道标准的2分查找的题目
// 分别用递推和递归实现
// 但是结果都不好。。
// 思维僵硬orz
// FIXME: 来自再战

// 递推方法：
// 执行用时 : 12 ms, 在Search Insert Position的C++提交中击败了16.06% 的用户
// 内存消耗 : 8.9 MB, 在Search Insert Position的C++提交中击败了0.27% 的用户

// 递归方法
// 执行用时 : 20 ms, 在Search Insert Position的C++提交中击败了8.43% 的用户
// 内存消耗 : 9 MB, 在Search Insert Position的C++提交中击败了0.27% 的用户




class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size();
        int mid = 0;
        while (end - begin > 1) {
            mid = floor((begin + end)/2);
            if (target > nums[mid]) {
                begin = mid;
            } else if (target > nums[mid]) {
                end = mid;
            } else if (target = nums[mid]) {
                return mid;
            }
        } 
        if (target > nums[begin]) {
            if (begin < end && target > nums[end]) {
                return begin + 2;
            } else {
                return begin + 1;
            }    
        } else {
            return begin;
        }

    }
};

// 递归版本

// class Solution {
// public:
//     int find_tar(vector<int>& nums, int begin, int end, int target) {
//         int mid = floor((begin +end)/2);
//         if (begin == end) {
        //     if (target > nums[begin]) {
        //         return begin + 1;
        //     } else {
        //         return begin;
        //     }
        // } else if (end - begin == 1) {
        //   if (target > nums[end]) {
        //         return end+1;
        //   } else if (target > nums[begin]) {
        //         return end;
        //     } else {
        //         return begin;
        //     }
        // }
//         if (target > nums[mid]) {
//            int a = find_tar(nums, mid, end, target);
//         } else if (target < nums[mid]) {
//             int a = find_tar(nums, begin, mid, target);
//         } else if (target = nums[mid]) {
//             return mid;
//         }
        
//     }
//     int searchInsert(vector<int>& nums, int target) {
//         int cnt = nums.size();
//         int ans = find_tar(nums, 0, cnt-1, target);
//         return ans;
//     }
// };