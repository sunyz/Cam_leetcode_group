/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-30 23:01:19
 * @LastEditTime: 2019-05-01 00:44:00
 */

//  * @Description: 正常的链表遍历
//  * 这里多申请了一个新的node节点，来指向原始的head，这样可以处理第一个就是要排除的情况
//  * 另一个node指针复制了新建的节点地址，用于最后的输出，因为第一个节点会变动
//  * 注意一些细微的逻辑的地方

// Runtime: 28 ms, faster than 99.65% of C++ online submissions for Remove Linked List Elements.
// Memory Usage: 11.1 MB, less than 99.16% of C++ online submissions for Remove Linked List Elements.


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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * tmp = new ListNode(0);
        ListNode * tmp2 = tmp;
        tmp->next = head;
        while (tmp != NULL) {
            if (tmp->next != NULL && tmp->next->val == val) {
                tmp->next = tmp->next->next;
                continue; // 这里我开始落下了。。
            }
            tmp = tmp->next; 
        }
        return tmp2->next;
    }
};