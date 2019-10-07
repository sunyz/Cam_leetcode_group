/*
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]

返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
执行结果：
通过
显示详情 

执行用时 :
16 ms
, 在所有 C++ 提交中击败了
97.73%
的用户
内存消耗 :
17.7 MB
, 在所有 C++ 提交中击败了
30.86%
的用户*/
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
    unordered_map<int, int> in_map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return NULL;
        // construct map
        
        for (int pre = 0; pre < preorder.size(); pre++) {
            in_map[inorder[pre]] = pre;
        }

        TreeNode* root = buildTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
        //new TreeNode(preorder[0]);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>&inorder, int pre_s, int pre_e, int in_s, int in_e) {
        //cout << "building:" << pre_s << " " << pre_e << " " << in_s << " " << in_e << endl;
        if (pre_e - pre_s == 1)
            return new TreeNode(preorder[pre_s]);
        assert(pre_e - pre_s == in_e - in_s);
        int r = preorder[pre_s];
        auto root = new TreeNode(preorder[pre_s]);
        int pos_r = in_map[r];
        int left_len = pos_r - in_s;
        if (pos_r > in_s) {
            
            root->left = buildTree(preorder, inorder, pre_s+1, pre_s+left_len+1, in_s, in_s + left_len);
        } else {
            root->left = NULL;
        }
        if (pos_r == in_e - 1) {
            root->right = NULL;
        } else {
            int right_len = in_e - pos_r;
            root->right = buildTree(preorder, inorder, pre_s + left_len+1, pre_e, in_s + left_len+1, in_e);
        }
        return root;
    }
};
