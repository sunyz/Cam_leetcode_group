/*
 * @Author: sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-06 23:15:32
 * @LastEditTime: 2019-04-06 23:54:45
 */

// * @Description: 没啥特别的，一次遍历是少不了的，然后题目
// 要求是O(1)的空间，所以想了想那就把不要的数据和末位交换
// 然后再移走末位数据好了，还可以省空间，时间复杂度也是O(N)
// 不过效果一般吧。。。。star 1的水平。。


// 执行用时 : 8 ms, 在Remove Element的C++提交中击败了25.86% 的用户
// 内存消耗 : 8.6 MB, 在Remove Element的C++提交中击败了0.39% 的用户


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int meet_cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                meet_cnt ++;
                nums[i] = nums[nums.size()-1];
                nums.pop_back(); //直接删除末尾元素
                i --;
            }
        }
        return nums.size();
    }
};