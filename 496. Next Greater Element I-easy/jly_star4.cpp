class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        std::unordered_map<int, int> m;
        std::stack<int> s;
        for (int i = 0; i < nums2.size(); i++) {
            while(!s.empty()) {
                if (s.top() < nums2[i]) {
                    
                    int t = s.top();
                    s.pop();
                    m[t] = nums2[i];
                } else {
                    break;
                }
            }
            s.push(nums2[i]);
            m[nums2[i]] = -1;
        }
        for (auto item : nums1) {
            res.push_back(m[item]);
        }
        return res;
    }
};
