/**
 * 按照我之前的unordered_map做法搞了一下，效果并不好
 * 执行用时 : 44 ms, 在Linked List Cycle II的C++提交中击败了10.00% 的用户
内存消耗 : 12.6 MB, 在Linked List Cycle II的C++提交中击败了5.07% 的用户
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int> m;
        ListNode* p = head;
        if (!head) return nullptr;
        while (p->next) {
            if (m.count(p) == 0)
                m.insert(make_pair(p,1));
            else
                return p;
            p = p->next;
        }
        return nullptr;
    }
};
