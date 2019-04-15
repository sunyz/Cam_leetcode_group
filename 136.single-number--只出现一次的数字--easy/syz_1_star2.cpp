/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-16 00:36:37
 * @LastEditTime: 2019-04-16 01:00:16
 */

//  * @Description: 我的做法是先排序，然后比较
//  * 其实不是O（n）的复杂度
//  * 然后看了解析，服气，神仙解法
//  * 用抑或来消除重复
//  * 交换律：a ^ b ^ c <=> a ^ c ^ b
//  * 任何数于0异或为任何数 0 ^ n => n
//  * 相同的数异或为0: n ^ n => 0
//  * 2 ^ 3 ^ 2 ^ 4 ^ 4等价于 2 ^ 2 ^ 4 ^ 4 ^ 3 => 0 ^ 0 ^3 => 3


// 执行用时 : 32 ms, 在Single Number的C++提交中击败了42.87% 的用户
// 内存消耗 : 9.6 MB, 在Single Number的C++提交中击败了76.23% 的用户

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for (int i=1;i < nums.size(); i+=2) {
            if (nums[i] != nums[i-1]) {
                return nums[i-1];
            }
        } 
        return nums[nums.size()-1];
    }
};

// 神仙解法
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(const auto &item:nums)
            res^=item;
        return res;
    }
};