//神仙算法，大概看了一下，基本都是这个思路解的，马克学习了
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, water = 0, minHeight = 0;
        while (l < r) {
            while (l < r && height[l] <= minHeight) {
                water += minHeight - height[l++];
            }
            while (l < r && height[r] <= minHeight) {
                water += minHeight - height[r--];
            }
            minHeight = min(height[l], height[r]);
        }
        return water;
    }
};
/*TODO: 我的解法思路很简单。两个for循环可以拆开，理论上可以优化到O(2)，也能满足该题的要求。但是暂时没有想好用什么数据结构，后面再改进一下
class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        if (height.size() < 2) {
            return 0;
        }
        int max_depth = *max_element(height.begin(), height.end());

        for (int i = 1; i <= max_depth; i++) {
            vector<int> index_t;
            for (int j = 0; j < height.size(); j++) {
                if (height[j] >= i) {
                    index_t.push_back(j);
                }
            }
            if(index_t.size() >= 2) {
                result += (index_t.back() - index_t.front() + 1 - index_t.size());
            }
        }
        return result;
    }
};
*/
