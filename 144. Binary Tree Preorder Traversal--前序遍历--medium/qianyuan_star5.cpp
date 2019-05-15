// 执行用时 : 4 ms, 在Binary Tree Preorder Traversal的C++提交中击败了99.11% 的用户
// 内存消耗 : 9.4 MB, 在Binary Tree Preorder Traversal的C++提交中击败了23.77% 的用户
// 复习知识点, no thing to say
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> S;
        TreeNode* node_t = root;
        while (1) {
            while (node_t != NULL) {
                res.push_back(node_t->val);
                S.push(node_t->right);
                node_t = node_t->left;
            }
            if (S.empty()) break;
            node_t = S.top();
            S.pop();
        }
        return res;
    }
};