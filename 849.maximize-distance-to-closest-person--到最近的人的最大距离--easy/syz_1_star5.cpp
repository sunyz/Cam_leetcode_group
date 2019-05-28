/*
 * @Author: sunyz
 * @Date: 2019-05-29 00:18:59
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @LastEditTime: 2019-05-29 00:38:20
 */

//  * @Description: 朴素的分情况
//  * 距离有三种情况
//  * 分别是左开右闭， 左右都闭，和左闭右开
//  * 这里的开闭指的是是否以1为边界
//  * 左边距离为i+1
//  * 中间距离为(j - i) / 2
//  * 右边距离为 j-i-1
//  * 注意加1减1即可

// 执行用时 : 12 ms, 在Maximize Distance to Closest Person的C++提交中击败了98.94% 的用户
// 内存消耗 : 9.9 MB, 在Maximize Distance to Closest Person的C++提交中击败了86.32% 的用户

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int current_max = 1;
        bool has_left = 0;
        int i,j=0;
        for (i=0; i<seats.size(); i++) {
            if (has_left == 0 && seats[i] == 0) {
                current_max = i + 1;
            } else if (seats[i] == 1) {
                has_left = 1;
                bool has_right = 0;
                for (j=i+1; j<seats.size(); j++) {
                    if (seats[j] == 1) {
                        has_right = 1;
                        break;
                    }
                }
                if (has_right == 1) {
                    int cur = (j - i) / 2;
                    current_max = max(cur, current_max);
                } else {
                    int cur = j - i - 1;
                    current_max = max(cur, current_max);
                    return current_max;
                }
                i = j - 1;
            }
        }
        return current_max;
    }
};
