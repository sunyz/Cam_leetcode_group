/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-13 22:38:32
 * @LastEditTime: 2019-04-14 01:14:56
 */

//  * @Description: 这货搞得我肝疼，算法想了好久。。。
//  * 开始时候是建立了差分的另一个vector，来比较。。直接思路错误
//  * 然后呢，用模拟注水的方式，即对每一个底层，逐层灌水，看每次能加多少，这里每次要
//  * 寻找左右两边的“水槽”，但是结果是最后的栗子过不去
//  * 再然后是在上一个思路的启发下，突然有了灵感，不是纵向上的灌水遍历，而是横向上遍历，
//  * 即对vectir中每一个数，其最后能容纳多少水
//  * 则其容纳水量为   min(左边最高槽高度, 右边最高槽高度) - 自身池底高度
//  * 左边的最高槽，因为是从左往右比，所以直接冒泡的方式即可
//  * 而右边的部分，是vector的剩余部分，用了std的max_element函数
//  * 开始时通过了但是很慢，是因为把右边的部分assign给了一个新的vector
//  * 这部分拷贝的开销太高了
//  * 后来了解了max_element的用法后。。。
//  * 直接对height原地操作就行了
//  * 然后时间空间都愉悦了hhhh

// 执行用时 : 12 ms, 在Trapping Rain Water的C++提交中击败了97.02% 的用户
// 内存消耗 : 8.9 MB, 在Trapping Rain Water的C++提交中击败了95.12% 的用户


class Solution {
public:
    int trap(vector<int>& height) {
        int cnt = height.size();
        int left_max = 0;
        int right_max = 0;
        int sum = 0;
        vector<int>::iterator biggest_r;
        for (int i=1; i<cnt-1;i++) {
            if (left_max + right_max == 0) {
                biggest_r = std::max_element(std::begin(height)+i+1, std::end(height));
                left_max = height[0];
                right_max = *biggest_r;
             } else {
                left_max = max(left_max, height[i-1]);
                if (height[i] == right_max) {
                    biggest_r = std::max_element(std::begin(height)+i+1, std::end(height));
                    right_max = *biggest_r;
                }   
             }
            sum += max(min(left_max, right_max) - height[i],0);
        }
        return sum;
    
    }
};

//  注水法，模拟过程，最后两组会超时
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         if (height.size() == 0) return 0;
//         int total_sum = 0;
//         int cnt = height.size();
//         int maxh = 0;
//         int i=0;
//         //灌水法
//         bool left_flag = false;
//         bool right_flag = false;
//         int left = 0;
//         int right = cnt -1;
//         bool zhushui_flag = false;
//         int shui_height = 1;
        
//         while (shui_height) {
//             int temp_left = 0;
//             int temp_right = 0;
//             shui_height --;
//             zhushui_flag = false;
//             left_flag = false;
//             right_flag = false;
//             left = cnt-1;
//             right = 0;
//             for (i=0; i < cnt; i++) {
//                 maxh = height[i]>maxh ? height[i] : maxh;
//                 if (!left_flag && height[i] > shui_height) { //左边的蓄水墙
//                     left_flag = true;
//                     left = i;
//                     // cout << left;
//                 }
//                 if (left_flag && i>left && height[i] <= shui_height) {
//                         temp_left ++;
//                 }
//                 if (!right_flag && height[cnt-1-i] > shui_height ) {//右边的蓄水墙
//                     right_flag = true;
//                     right = cnt - 1 - i;
//                     //cout << right;
//                 }
//                 if (right_flag && cnt-1-i<right && height[cnt-1-i] <= shui_height) {
//                         temp_right ++;
//                 }
//                 if (left_flag && right_flag && ((right - left)>1) ) {
//                     zhushui_flag = true;
//                 }
//                 if (zhushui_flag) {
//                     for (int j=i+1; j<cnt-i-1; j++) {
//                         if (height[j] <= shui_height) {
//                             total_sum ++;
//                         }
//                     }
//                     total_sum = total_sum + temp_left + temp_right;
                    
//                     break;
//                 } 
//             }
//             //cout << endl<<total_sum<<endl;
//             if (zhushui_flag) {
//                 shui_height += 2;
//             } else{
//                 break;
//             }
//         }
//         // 开始逐渐加高水的高度

//         return total_sum;

//     }
// };