// 执行用时 : 4 ms, 在Invert Binary Tree的C++提交中击败了96.23% 的用户
// 内存消耗 : 9.3 MB, 在Invert Binary Tree的C++提交中击败了8.75% 的用户
// 第一种解法：经典的迭代题目
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        if (root->left || root->right) {
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            invertTree(root->right);
            invertTree(root->left);
            return root;
        } else {
            return root;
        }
    }
};
// 执行用时 : 4 ms, 在Invert Binary Tree的C++提交中击败了96.23% 的用户
// 内存消耗 : 9.1 MB, 在Invert Binary Tree的C++提交中击败了37.89% 的用户
// 第二种解法： 层序遍历，建议！
// 和第一种解法相比，迭代的栈空间更小，而递归的栈空间更大！
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> Q;
        if(root) Q.push(root);
        while (!Q.empty()) {
            TreeNode* node_t = Q.front();
            // exchange left node & right node
            TreeNode* tmp = node_t->left;
            node_t->left = node_t->right;
            node_t->right = tmp;
            if(node_t->left) Q.push(node_t->left);
            if(node_t->right) Q.push(node_t->right);
            Q.pop();
        }
        return root;
    }
};
