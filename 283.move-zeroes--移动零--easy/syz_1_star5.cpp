/*
 * @Author: sunyz
 * @Date: 2019-05-25 00:09:22
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @LastEditTime: 2019-05-25 00:25:18
 */

//  * @Description: 和快慢指针的思路是完全一样的
//  * 快指针移动，慢指针写数
//  * 剩余部分补0

// 执行用时 : 20 ms, 在Move Zeroes的C++提交中击败了97.17% 的用户
// 内存消耗 : 9.5 MB, 在Move Zeroes的C++提交中击败了51.91% 的用户

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        int cnt = nums.size();
        for (fast; fast < cnt; fast++) {
            if (nums[fast] != 0) {
                nums[slow++] = nums[fast];
            }
        }
        while (slow < cnt) {
            nums[slow++] = 0;
        }
    }
};


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i])
                swap(nums[k++], nums[i]);
        }
    }
};