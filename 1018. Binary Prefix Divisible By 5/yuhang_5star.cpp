class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
    uint8_t sum = 0;
    for (auto i : A) {
        sum = (sum * 2 + i) % 5;
        result.push_back(sum == 0);
    }
    return result;
    }
    vector<bool> result;
};
