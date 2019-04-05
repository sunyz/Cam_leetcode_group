/**
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
Example: 
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

暴力求解，效果比较差
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result;
        ListNode* p;
        ListNode* node;
        if (l1 && l2) {
            if (l1->val > l2->val) {
                node = new ListNode(l2->val);
                l2 = l2->next;
                result = node;
                p = result;
            } else {
                node = new ListNode(l1->val);
                l1 = l1->next;
                result = node;
                p = result;
            }
        } else {
            if (l1)
                return l1;
            else
                return l2;
        }
        while (l1 && l2) {
            if (l1->val > l2->val) {
                node = new ListNode(l2->val);
                l2 = l2->next;
            } else {
                node = new ListNode(l1->val);
                l1 = l1->next;
            }
            p->next = node;
            p = node;
        }
        if (l1) {
            while(l1) {
                node = new ListNode(l1->val);
                p->next = node;
                p = node;
                l1 = l1->next;
            }
        } else {
            while(l2) {
                node = new ListNode(l2->val);
                p->next = node;
                p = node;
                l2 = l2->next;
            }
        }
        
        return result;
    }
};
