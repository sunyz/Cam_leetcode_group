// 执行用时 : 8 ms, 在Binary Tree Postorder Traversal的C++提交中击败了96.59% 的用户
// 内存消耗 : 9.1 MB, 在Binary Tree Postorder Traversal的C++提交中击败了60.53% 的用户
// 二叉树遍历的经典题目，我使用栈的方法解决的
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        TreeNode* last = NULL;
        while (root || !todo.empty()) {
            if (root) {
                todo.push(root);
                root = root -> left;
            } else {
                TreeNode* node = todo.top();
                if (node -> right && last != node -> right) {
                    root = node -> right;
                } else {
                    nodes.push_back(node -> val);
                    last = node;
                    todo.pop();
                }
            }
        }
        return nodes;
    }
};