/*
 * @Author: sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-21 22:10:38
 * @LastEditTime: 2019-04-21 23:18:09
 */

//  * @Description: emmm感觉是暴力的二分法
//  * 画图，看图盘逻辑
//  * 具体看注释吧。。。
//  * 分情况讨论


// 执行用时 : 8 ms, 在Search in Rotated Sorted Array的C++提交中击败了96.98% 的用户
// 内存消耗 : 8.7 MB, 在Search in Rotated Sorted Array的C++提交中击败了85.90% 的用户


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while (left <= right) {
            mid = (left + right)/2;
            if (nums[left] < nums[right]) { //说明处于某一个单调悬臂的区间
                if (target == nums[mid]) {
                    return mid;
                } else if (target < nums[mid]) {
                    right = mid - 1; // 闭区间均可取值
                } else {
                    left = mid + 1;
                }
            } else { //左边大于右边，说明此时跨了悬臂
                if (target == nums[mid]) {
                    return mid;
                } else if (target < nums[mid]) {
                    if (nums[mid] >= nums[left]) { // 说明中点在左悬臂上 R<L<M
                        if (nums[left] <= target) {
                            right = mid - 1;
                        } else {
                            left = mid + 1;
                        }  
                    } else { 
                        // 中点在右悬臂上，目标点比中点小，应该在右悬臂上，但是此时左边不能确定
                        // 所以仍然只变动右边
                        if (mid > 0 && nums[mid] > nums[mid - 1]) {//确保左边仍然在右悬臂
                            right = mid - 1;
                        } else {
                            break; // 都在左悬臂了，不可能再有更小的了，提前结束吧
                        }
                    }
                } else {
                    if (nums[mid] >= nums[left]) { 
                        // 说明中点在左悬臂上 R<L<M, 目标比中点大，应该在左悬臂上
                        // 但是此时左悬臂的右边界不确定，只变动左边
                        if (mid + 2 < nums.size() && nums[mid+ 1] > nums[mid]) {//确保右边仍然在左悬臂
                            left = mid + 1;
                        } else {
                            break; // mid+1都在右悬臂了，不可能再有比mid更大的了，提前结束吧
                        }
                    } else { 
                        if (nums[right] >= target) {
                            left = mid + 1;
                        } else {
                            right = mid - 1;
                        }
                        
                    }
                    
                }
            }
        }
        return -1; 
    }
};