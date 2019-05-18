// 执行用时 : 8 ms, 在Binary Tree Pruning的C++提交中击败了92.71% 的用户
// 内存消耗 : 9.9 MB, 在Binary Tree Pruning的C++提交中击败了25.00% 的用户
//标准答案，剪枝的时候，需要注意不能裁剪掉多余的节点，理解两种剪枝的区别，这也是本题的关键点
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root) {
            if (root->left) root->left = pruneTree(root->left);
            if (root->right)  root->right = pruneTree(root->right);
            // 正确的剪枝
            if (!root->left && !root->right && root->val == 0) root = NULL;
            /*错误的剪枝
            if (root->left && root->left->val == 0) root->left = NULL;
            if (root->right && root->right->val == 0) root->right = NULL;
            */
        } else {
            return root;
        }
        return root;
    }
};