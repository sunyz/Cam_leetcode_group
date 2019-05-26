// 见syz的提交
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_gain = 0;
        if (prices.size() < 2)
            return 0;
        int low_point = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                int diff = prices[i] - low_point;
                max_gain = (max_gain < diff) ? diff : max_gain;
            } else {
                low_point = (low_point > prices[i]) ? prices[i] : low_point;
            }
            
        }
        return max_gain;
    }
};
