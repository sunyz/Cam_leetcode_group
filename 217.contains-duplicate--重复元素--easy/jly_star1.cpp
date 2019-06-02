/*
同syz，不知道为什么前几名都是排序，时间复杂度应该不如set啊
执行用时 : 104 ms, 在Contains Duplicate的C++提交中击败了18.76% 的用户
内存消耗 : 16.5 MB, 在Contains Duplicate的C++提交中击败了34.63% 的用户
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
            //cout << i;
            if(s.size() < i + 1)
                return true;
        }
        return false;
    }
};
