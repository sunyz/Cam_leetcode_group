// 执行用时 : 8 ms, 在Binary Tree Level Order Traversal的C++提交中击败了98.25% 的用户
// 内存消耗 : 14 MB, 在Binary Tree Level Order Traversal的C++提交中击败了30.01% 的用户
// 深度遍历，难点在于如何知道节点的深度
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<vector<int>> res;
        if(root) Q.push(root);
        while (!Q.empty()) {
            int len = Q.size();
            vector<int> tmp;
            for (int i = 0; i < len; i++) {
                tmp.push_back(Q.front()->val);
                if (Q.front()->left) Q.push(Q.front()->left);
                if (Q.front()->right) Q.push(Q.front()->right);
                Q.pop();
            }
            res.push_back(tmp);
        }
        return res;
    }
};