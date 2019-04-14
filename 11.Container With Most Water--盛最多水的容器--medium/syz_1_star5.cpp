/*
 * @Author: sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-14 15:03:33
 * @LastEditTime: 2019-04-14 15:22:04
 */

//  * @Description: 这个题如果用暴力的话，就是C(2,n)也就是O(n^2)的复杂度，对于中级题目肯定是不行的
//  * 所以这里考虑使用双指针
//  * 假设有(i, ai), (j, aj), 则面积是  (j - i) * min(ai, aj);
//  * 假设最开始i和j位于两端，则 j-i必定是逐渐减小的，则要想让面积是变大的，则只可能是
//  * min(ai, aj) 【可能】变大，则做法就是移动ai和aj中较短的那个，使得其移动一次，再进行
//  * 比较，决定是否更新maxarea
//  * NOTE: 这里在移动的时候，其实可以无条件的只移动一次，但是我觉得这样并不能保证右边是单调的，
//  * 所以我设计的是每次移动都一定移动到比当前大的位置，即下面的while循环，同时保留了至少移动一次
//  * 然后再while，防止直接while导致卡住不移动
//  * 不过结果上看这个while加不加几乎没有区别

// 执行用时 : 24 ms, 在Container With Most Water的C++提交中击败了95.17% 的用户
// 内存消耗 : 9.7 MB, 在Container With Most Water的C++提交中击败了82.09% 的用户


class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        int left = 0;
        int right = height.size()-1;
        while (right > left) {
            maxarea = max(maxarea, (right-left)*min(height[left], height[right]));
            if (height[left] > height[right]) {
                right --;
                while (right > left && height[right] < height[right + 1]) {
                    right --;
                }
                
            } else {
                left ++;
                while (right > left && height[left - 1] > height[left]) {
                    left ++;
                }
            }
        }
        return maxarea;
    }
};