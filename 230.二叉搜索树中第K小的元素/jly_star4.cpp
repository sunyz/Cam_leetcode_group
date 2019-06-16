/*
给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
执行用时 :
32 ms
, 在所有C++提交中击败了
85.95%
的用户
内存消耗 :
21.8 MB
, 在所有C++提交中击败了
19.26%
的用户
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int count_ = 0;
    int k_;
    int res_;
    // i can turn it into a vector, but not good
    int kthSmallest(TreeNode* root, int k) {
        k_ = k;
        traverse(root);
        return res_;
    }
    void traverse(TreeNode* node) {
        // cout << count_;
        if (count_ >= k_)
            return;
        if (node->left)
            traverse(node->left);
        count_++;
        if (count_== k_)
            res_ = node->val;
        if (node->right)
            traverse(node->right);
    }
};
