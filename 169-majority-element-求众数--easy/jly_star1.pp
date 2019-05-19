// 我还没看神仙算法呢。。
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int size = nums.size() / 2;
        for (auto it : nums) {
            if (m.count(it))
                m[it]++;
            else
                m[it] = 1;
            if (m[it] > size)
                return it;
        }
        return -1;
    }
};
