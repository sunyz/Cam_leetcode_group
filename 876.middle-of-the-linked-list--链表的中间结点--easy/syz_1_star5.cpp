/*
 * @Author: sunyz
 * @Date: 2019-05-30 23:48:12
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @LastEditTime: 2019-05-31 00:13:11
 */

//  * @Description: 快慢指针
//  * 判断奇偶，如果是偶数要补一次

// 执行用时 : 4 ms, 在Middle of the Linked List的C++提交中击败了95.49% 的用户
// 内存消耗 : 8.4 MB, 在Middle of the Linked List的C++提交中击败了56.65% 的用户

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast->next !=NULL) {
            return slow->next;
        }
        return slow;
    }
};