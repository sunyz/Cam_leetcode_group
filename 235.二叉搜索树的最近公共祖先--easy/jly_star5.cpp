/**
卧槽我没看到这是一个二叉搜索树，但我写的这个玩意儿还挺争气
执行用时 : 48 ms, 在Lowest Common Ancestor of a Binary Search Tree的C++提交中击败了93.19% 的用户
内存消耗 : 26 MB, 在Lowest Common Ancestor of a Binary Search Tree的C++提交中击败了5.28% 的用户
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
    bool found = false;
    TreeNode* p_;
    TreeNode* q_;
    TreeNode* res_;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        p_ = p;
        q_ = q;
        traverse(root);
        return res_;
    }
    int traverse(TreeNode* node) {
        int l = 0;
        if (node->left) {
            l = traverse(node->left);
        }
        int r = 0;
        if (node->right) {
            r = traverse(node->right);
        }
        // cout << found << endl;
        if (found) {
            return 0;
        }
        int self = (node == p_ || node == q_) ? 1 : 0;
        if (l + r + self == 2) {
            found = true;
            res_ = node;
            // cout << "found:" << node->val << std::endl;
        }
        
        return l + r + self;
    }
};
