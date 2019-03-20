/*
 * @Author: sunyz
 * @LastEditors: Please set LastEditors
 * @Date: 2019-03-20 11:24:36
 * @LastEditTime: 2019-03-20 11:48:19
 * 
 * @Description: 使用map来实现O(logN)的查找速度，外层循环一边插入map一边
 * 寻找之前是否已有target-(*iter),因为附加条件是只有一个结果，所以可以直接返回，
 * 综合的时间复杂度是O(NlogN)
 * but,也曾尝试用过unordered_map来存储和查找，unordered_map本身是hash表，能实现
 * O(1)的查找速度，综合下来就是O(N)的复杂度，但是实际效果提升不大，时间在好的时候
 * 会达到16ms，但是坏的时候会是32ms，不如map稳定。

 * 执行用时 : 20 ms, 在Two Sum的C++提交中击败了62.94% 的用户
 * 内存消耗 : 10.3 MB, 在Two Sum的C++提交中击败了0.82% 的用户

 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        ans.reserve(2);
        
        std::map<int, int> map;
        std::map<int, int>::iterator it;
        int i = 0;
        for (auto iter = nums.begin(); iter != nums.end(); iter++){
             map.insert(std::make_pair(*iter, i));         
             if (((it = map.find(target-(*iter))) != map.end()) && (it->second != i)) {                      
                 ans.push_back(it->second);
                 ans.push_back(i);
                 map.clear();
                 return ans;
             }
             i++;
        }
        return ans;
    }
};