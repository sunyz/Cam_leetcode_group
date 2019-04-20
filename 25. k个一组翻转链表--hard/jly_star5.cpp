/**
给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。
示例 :
给定这个链表：1->2->3->4->5
当 k = 2 时，应当返回: 2->1->4->3->5
当 k = 3 时，应当返回: 3->2->1->4->5
说明 :
你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换

执行用时 : 32 ms, 在Reverse Nodes in k-Group的C++提交中击败了95.97% 的用户
内存消耗 : 9.9 MB, 在Reverse Nodes in k-Group的C++提交中击败了74.23% 的用户

这题就是考翻转链表，是24题的超集，就是耗时费劲，磕出来就行了，另外注意末尾不足的要保留顺序。
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k < 2)
            return head;
        ListNode* p1;
        ListNode* p2;
        ListNode* p3;
        ListNode* head_sub_list;
        ListNode* prev_last = new ListNode(-1);
        prev_last->next = head;
        ListNode* dummy = prev_last;
        head_sub_list = head;
        while(true) {
            try {
                p1 = head_sub_list;
                for (int16_t i = 0; i < k; i++) {
                    if (p1)
                        p1 = p1->next;
                    else
                        throw 1;
                }
            }
            catch(int i) {
                // cout << "catch";
                break;
            }
            p1 = head_sub_list;
            cout << p1->val << endl;
            p2 = head_sub_list->next;
            p3 = p2->next;
            int16_t counter = 0;
            while(counter < k - 1) {
                p2->next = p1;
                p1 = p2;
                p2 = p3;
                if (p3)
                    p3 = p3->next;
                counter++;
            }
            prev_last->next = p1;
            prev_last = head_sub_list;
            head_sub_list->next = p2;
            head_sub_list = p2;
            
            
            // cout << "last:" << p1->val << endl;
        }
        return dummy->next;
        
    }
};
