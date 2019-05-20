/*
 * @Author: sunyz
 * @Date: 2019-05-20 23:53:57
 * @LastEditors: sunyz
 * @LastEditTime: 2019-05-21 00:03:53
 */


//  * @Description: stl大法好
//  * 全程库函数调用
//  * 其实变相相当于用set再交集

// 执行用时 : 4 ms, 在Intersection of Two Arrays的C++提交中击败了100.00% 的用户
// 内存消耗 : 9.1 MB, 在Intersection of Two Arrays的C++提交中击败了70.55% 的用户

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> c;
        // 先排序
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        // 调用函数做交集
        set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),inserter(c, c.begin()));
        // 删除重复元素
        c.erase(unique(c.begin(), c.end()), c.end());
        return c;
    }
};