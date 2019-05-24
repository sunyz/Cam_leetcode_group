#执行用时 : 36 ms, 在Two Sum的C++提交中击败了55.97% 的用户
#内存消耗 : 10.7 MB, 在Two Sum的C++提交中击败了5.71% 的用户
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> in_subs;
        for (int i = 0; i < nums.size(); i++) {
            in_subs[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            cout << nums.size() << endl;
            int yushu = target - nums[i];
            auto item = in_subs.find(yushu);
            cout << i << endl;
            if (item != in_subs.end() && item->second != i) {
                cout << "hhh" << item->first << item->second << endl;
                return {i, item->second};
            } 
            cout << i << nums.size();
        }
        return {0,0};
    }
};
