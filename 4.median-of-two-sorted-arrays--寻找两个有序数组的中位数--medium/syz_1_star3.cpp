/*
 * @Author: sunyz
 * @Date: 2019-05-17 14:32:11
 * @LastEditors: sunyz
 * @LastEditTime: 2019-05-17 14:35:19
 */

//  * @Description: 暴力合并，排序
//  * 排序的复杂度是O(log(m+n))
//  * 这样感觉并不好。。。
//  * FIXME: 再看好解法

// Runtime: 28 ms, faster than 70.32% of C++ online submissions for Median of Two Sorted Arrays.
// Memory Usage: 10.2 MB, less than 64.76% of C++ online submissions for Median of Two Sorted Arrays.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        std::sort (nums1.begin(), nums1.end());
        int cnt = nums1.size();
        if (cnt % 2 == 0) {
            return (nums1[cnt/2 - 1] + nums1[cnt/2]) / 2.0;
        } else {
            return nums1[(cnt-1)/2];
        }
        return 0;
    }
};