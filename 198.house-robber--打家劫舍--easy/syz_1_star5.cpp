/*
 * @Author: sunyz
 * @LastEditors: sunyz
 * @Date: 2019-05-01 23:45:29
 * @LastEditTime: 2019-05-01 23:50:52
 */

//  * @Description: 标准的动态规划
//  * dp: a[i] = max(a[i-1], a[i-2] + nums[i])
//  * 即第i家时能获得的最大利润，应该等于前i-1家时的利润
//  * （因为不能连续）， 或者前i-2家的利润再加上这第i家利润
//  * 中的较大值（注意max位置）
//  * 然后从递归改成递推
 

// 执行用时 : 8 ms, 在House Robber的C++提交中击败了96.38% 的用户
// 内存消耗 : 8.6 MB, 在House Robber的C++提交中击败了78.89% 的用户

class Solution {
public:    
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int a1 = nums[0]; // 前i-2家最大利润
        int a2 = max(nums[0], nums[1]); // 前i-1家利润
        int ans = a2;
        for (int n=2; n<nums.size(); n++) {
            ans = max(a2, a1 + nums[n]);
            a1 = max(a2,a1); // 更新前i-2家利润
            a2 = ans; // 更新
        }
        return ans;
    }
};