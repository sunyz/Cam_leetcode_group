// 执行用时 : 4 ms, 在Binary Tree Inorder Traversal的C++提交中击败了98.68% 的用户
// 内存消耗 : 9.3 MB, 在Binary Tree Inorder Traversal的C++提交中击败了38.44% 的用户
// 经典题目，标准答案的解法，简单清晰，值得学习
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vector;
        stack<TreeNode *> stack;
        TreeNode *pCurrent = root;
        
        while(!stack.empty() || pCurrent)
        {
            if(pCurrent)
            {
                stack.push(pCurrent);
                pCurrent = pCurrent->left;
            }
            else
            {
                TreeNode *pNode = stack.top();
                vector.push_back(pNode->val);
                stack.pop();
                pCurrent = pNode->right;
            }
        }
        return vector;
    }
};