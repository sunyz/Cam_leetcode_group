// 执行用时 : 52 ms, 在Merge Two Binary Trees的C++提交中击败了96.59% 的用户
// 内存消耗 : 19.3 MB, 在Merge Two Binary Trees的C++提交中击败了33.86% 的用户
// 递归的思路很简单
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 && t2) {
            int val = t1->val + t2->val;
            TreeNode* root = new TreeNode(val);
            root->left = mergeTrees(t1->left, t2->left);
            root->right = mergeTrees(t1->right, t2->right);
            return root;
        } else {
            return t1 ? t1 : t2; 
        }
    }
};