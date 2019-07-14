/*给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。
执行用时 :
16 ms
, 在所有 C++ 提交中击败了
39.16%
的用户
内存消耗 :
17.2 MB
, 在所有 C++ 提交中击败了
6.16%
的用户
递归可能效率差*/
class Solution {
public:
    vector<vector<int>> res_;
    vector<vector<int>> subsets(vector<int>& nums) {
        //res_.push_back(vector<int>());
        vector<int> null;
        DFS(nums, 0, null);
        return res_;
    }
    void DFS(vector<int>& nums, int curr, vector<int>& base) {
        if (curr == nums.size()) {
            res_.push_back(base);
            return;
        }
        DFS(nums, curr+1, base);
        auto copy = vector<int>(base);
        copy.push_back(nums[curr]);
        DFS(nums, curr+1, copy);
        
    }
};
