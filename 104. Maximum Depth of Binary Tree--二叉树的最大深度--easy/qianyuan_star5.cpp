// 执行用时 : 24 ms, 在Maximum Depth of Binary Tree的C++提交中击败了94.23% 的用户
// 内存消耗 : 19.4 MB, 在Maximum Depth of Binary Tree的C++提交中击败了41.00% 的用户
// 和145题十分类似，只用修改两三行就可以通过
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*> Q;
        if (root) {
            Q.push(root);
        }
        while (!Q.empty()) {
            int len = Q.size();
            for (int i = 0; i < len; i++) {
                TreeNode* tmp = Q.front();
                if (tmp->left != NULL) Q.push(tmp->left);
                if (tmp->right != NULL) Q.push(tmp->right);
                Q.pop();
            }
            depth++;
        }
        return depth;
    }
};