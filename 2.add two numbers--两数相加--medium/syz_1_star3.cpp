/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Date: 2019-03-21 00:10:52
 * @LastEditTime: 2019-04-08 01:36:13
 */

//  * @Description: 基本就是锻炼链表的基本操作，没用到什么tricky的技巧
//  * 两种特殊情况可以直接返回
//  * 注意如果两个链表都空的时候，也要判断进位是否还有剩下
// NOTE:  here is a useful html for learnning base operation of listnode
//       https://segmentfault.com/a/1190000002490878

// 执行用时 : 40 ms, 在Add Two Numbers的C++提交中击败了68.76% 的用户
// 内存消耗 : 10.2 MB, 在Add Two Numbers的C++提交中击败了0.94% 的用户

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *out = new ListNode(0);
        ListNode *tail = out;
        int jinwei = 0;
        int tmp_ans;
        while (l1 != NULL && l2 != NULL) {
            tmp_ans = (l1->val + l2->val + jinwei) % 10;
            jinwei = (l1->val + l2->val + jinwei) / 10;
            l1 = l1->next;
            l2 = l2->next;
            ListNode *tmp = new ListNode(tmp_ans);
            tail->next = tmp;
            tail =tmp;

        }
        while (l1 != NULL) {
            tmp_ans = (l1->val + jinwei) % 10;
            jinwei = (l1->val + jinwei) / 10;
            l1 = l1->next;
            ListNode *tmp = new ListNode(tmp_ans);
            tail->next = tmp;
            tail = tmp;
        }
        while (l2 != NULL) {
           tmp_ans = (l2->val + jinwei) % 10;
            jinwei = (l2->val + jinwei) / 10;
            l2 = l2->next;
            ListNode *tmp = new ListNode(tmp_ans); 
            tail->next = tmp;
            tail = tmp;
        }
        if (jinwei != 0) {
             ListNode *tmp = new ListNode(1); 
            tail->next = tmp;
            tail = tmp;
        }
    //    ListNode *t = out;
    //    while (t != NULL) {
    //      cout<< t->val <<endl;
    //      t = t->next;
    //    }
        return out->next; 
    }
};