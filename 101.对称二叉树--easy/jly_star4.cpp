//给定一个二叉树，检查它是否是镜像对称的。
/*
执行用时 :8 ms, 在所有 C++ 提交中击败了89.42%的用户
内存消耗 :14.6 MB, 在所有 C++ 提交中击败了94.12%的用户
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
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return isSym(root->left, root->right);
    }
    bool isSym(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr)
            return true;
        else if (left == nullptr || right == nullptr)
            return false;
        if (left->val != right->val)
            return false;
        return isSym(left->left, right->right) && isSym(left->right, right->left);
    }
};
