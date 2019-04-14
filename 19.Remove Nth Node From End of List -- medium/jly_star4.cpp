/**
Given a linked list, remove the n-th node from the end of list and return its head.
Example:
Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
执行用时 : 16 ms, 在Remove Nth Node From End of List的C++提交中击败了83.29% 的用户
内存消耗 : 8.4 MB, 在Remove Nth Node From End of List的C++提交中击败了90.72% 的用户
挺经典的题目，我好像见过，所以没遇到什么困难。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* front;
        ListNode* rear;
        rear = head;
        // initialize
        for (short i = 0; i < n; i++) {
            rear = rear->next;
        }
        if (!rear) {
            head = head->next;
            return head;
        }
        
        front = head;
        while (rear->next) {
            rear = rear->next;
            front = front->next;
        }
        // delete
        front->next = front->next->next;
        return head;
    }
};
