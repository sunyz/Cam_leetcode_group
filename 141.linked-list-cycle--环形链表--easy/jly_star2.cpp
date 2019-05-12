/**
之前没接触过判环以及快慢指针，自己想的用哈希来搞了一下。然后才知道还有快慢指针的方法
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> m;
        ListNode* p = head;
        if (!head) return false;
        while (p->next) {
            if (m.count(p) == 0)
                m.insert(make_pair(p,1));
            else
                return true;
            p = p->next;
        }
        return false;
    }
};
