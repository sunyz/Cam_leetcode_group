/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Date: 2019-05-08 00:28:56
 * @LastEditTime: 2019-05-08 00:30:33
 */

//  * @Description: 标准双指针

// 执行用时 : 12 ms, 在Two Sum II - Input array is sorted的C++提交中击败了96.45% 的用户
// 内存消耗 : 9.5 MB, 在Two Sum II - Input array is sorted的C++提交中击败了21.26% 的用户


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left  = 0;
        int right = numbers.size() - 1;
        vector<int> ans;
        while(left < right) {
          if (numbers[left] + numbers[right] > target) {
            right --;
          } else if (numbers[left] + numbers[right] < target) {
            left ++;
          } else {
            vector<int> ans = {left+1, right+1};
            return ans;
          }
        }
        return ans;
    }
};