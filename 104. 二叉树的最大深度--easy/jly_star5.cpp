/**
给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
说明: 叶子节点是指没有子节点的节点。
示例：
给定二叉树 [3,9,20,null,null,15,7]，
    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
执行用时 : 24 ms, 在Maximum Depth of Binary Tree的C++提交中击败了96.44% 的用户
内存消耗 : 19.6 MB, 在Maximum Depth of Binary Tree的C++提交中击败了5.60% 的用户
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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (root->left || root->right)
            return traverse(root);
        else
            return 1;
    }
    int traverse(TreeNode* root) {
        if (!root->left && !root->right)
            return 1;
        int left,right;
        if (root->left)
            left = traverse(root->left);
        else
            left = 0;
        if (root->right)
            right = traverse(root->right);
        else
            right = 0;
        return max(left, right) + 1;
    }
};
