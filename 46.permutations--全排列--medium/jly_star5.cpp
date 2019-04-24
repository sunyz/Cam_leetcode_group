/**
题目见syz的提交
我一开始想到用递归了，但是具体怎么处理选过的数据我没想清楚
首先看了一下评论区，用python的，每次从剩余的数组中删除一个，进行递归。肯定效率不高
然后看了一下哲霸的，嗯，果然也是递归，而且是把用过的数字交换到前面
果断把syz的代码提交上去，效果比他自己的还好，击败了94%
然后看了一下效果最好的代码，嗯，用了递归，但是人家更骚，搞了个dfs。我给改了改，如下。
但其实性能跟syz的一模一样。。。
执行用时 : 20 ms, 在Permutations的C++提交中击败了94.72% 的用户
内存消耗 : 9.3 MB, 在Permutations的C++提交中击败了67.93% 的用户
*/
class Solution {
public:
    int size_;
    vector<bool> status_;
    vector<int> tmp_;
    vector<vector<int>> res;
    
    vector<vector<int>> permute(vector<int>& nums) {
        size_ = nums.size();
        
        if (size_ == 0)
            return res;
        // init status_ as false
        vector<bool> t(size_, false);
        status_ = t;
        
        dfs(nums);
        return res;
        
    }
    
    void dfs(vector<int>& nums) {
        if (tmp_.size() == size_) {
            res.push_back(tmp_);
            return;
        } else {
            for (int i = 0; i < size_; i++) {
                if (!status_[i]) {
                    
                    status_[i] = true;
                    tmp_.push_back(nums[i]);
                    dfs(nums);
                    status_[i] = false;
                    tmp_.pop_back();
                }
            }
        }
    }
};
