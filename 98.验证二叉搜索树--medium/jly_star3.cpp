/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：


	节点的左子树只包含小于当前节点的数。
	节点的右子树只包含大于当前节点的数。
	所有左子树和右子树自身必须也是二叉搜索树。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
执行用时 :
20 ms
, 在所有 C++ 提交中击败了
73.63%
的用户
内存消耗 :
20.8 MB
, 在所有 C++ 提交中击败了
36.16%
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
    bool isValidBST(TreeNode* root) {
        int min = -1;
        int max = -1;
        return traverse(root, min, max);
    }
    
    bool traverse(TreeNode* root, int& min, int& max) {
        if (!root) {
            return true;
        }
        int tmp1, tmp2;
        bool ret = true;
        if (root->left) {
            ret = traverse(root->left, tmp1, tmp2);
            if (!ret || tmp2 >= root->val)
                return false;
            min = tmp1;
            
        } else {
            min = root->val;
        }
        if (root->right) {
            ret = traverse(root->right, tmp1, tmp2);
            if (!ret || tmp1 <= root->val)
                return false;
            max = tmp2;
        } else {
            max = root->val;
        }
        return ret;
    }
};
