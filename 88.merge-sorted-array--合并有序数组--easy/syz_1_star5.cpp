/*
 * @Author: sunyz
 * @Date: 2019-05-13 09:41:49
 * @LastEditors: sunyz
 * @LastEditTime: 2019-05-13 10:44:24
 */

//  * @Description: 倒着挨个取数就行了
//  * 注意某个到0后的特殊处理

// 执行用时 : 8 ms, 在Merge Sorted Array的C++提交中击败了98.22% 的用户
// 内存消耗 : 8.7 MB, 在Merge Sorted Array的C++提交中击败了83.97% 的用户

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n;
        m --;
        n --;
        while (k) {
            if (m != -1 && (n == -1 || nums2.size() == 0 || nums1[m] > nums2[n])) {
                nums1[k - 1] = nums1[m--];
            } else {
                nums1[k - 1] = nums2[n--];
            }
            //cout << k-1  <<" " <<nums1[k-1] << endl;
            k --;
        }
    }
};