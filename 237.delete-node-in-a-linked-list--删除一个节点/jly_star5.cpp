/**
蛋疼的题，可以用来做我司面试题，当面试的人不懂c++的时候
难点在于理解这个蛋疼的函数参数。
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* next = node->next;
        node->val = next->val;
        node->next = next->next;
        delete next;
    }
};
