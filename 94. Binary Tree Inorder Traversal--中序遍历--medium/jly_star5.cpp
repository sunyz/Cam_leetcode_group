/*
执行用时 :
4 ms
, 在所有 C++ 提交中击败了
90.55%
的用户
内存消耗 :
9.2 MB
, 在所有 C++ 提交中击败了
48.81%
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
    vector<int> res_;
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return res_;
    }
    void traverse(TreeNode* root) {
        if (root == NULL)
            return;
        traverse(root->left);
        res_.push_back(root->val);
        traverse(root->right);
    }
};
