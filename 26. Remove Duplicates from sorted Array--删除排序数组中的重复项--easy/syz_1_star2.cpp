/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-08 23:54:28
 * @LastEditTime: 2019-04-09 00:04:10
 */

//  * @Description: 由于先做了下面那到移除数字的题，这个题思路完全一致，用两个指针遍历，
//  * 其一遍历找不同，然后原地覆盖指针2对应的位置
//  * 
//  * 看了下标准解法，是一致的，暂时想不到比O(N)还能更快的方式了


// 执行用时 : 32 ms, 在Remove Duplicates from Sorted Array的C++提交中击败了36.67% 的用户
// 内存消耗 : 9.9 MB, 在Remove Duplicates from Sorted Array的C++提交中击败了0.95% 的用户

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int i=1;
        int j=1;
        while(j<nums.size()){
            if(nums[j]!=nums[j-1]){
                nums[i++]=nums[j];
            }
          j++;
        }
       return i;
    }
};