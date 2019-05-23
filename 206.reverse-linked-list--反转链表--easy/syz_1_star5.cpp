/*
 * @Author: sunyz
 * @Date: 2019-05-24 00:32:46
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @LastEditTime: 2019-05-24 01:43:49
 */

//  * @Description: 迭代就是调整next的位置，反复操作
//  * 迭代核心是知道返回值后，应该在末尾添加当前head
//  * 而末尾则是head->next
//  * 
 
// 迭代方法：

// 执行用时 : 12 ms, 在Reverse Linked List的C++提交中击败了97.67% 的用户
// 内存消耗 : 9.2 MB, 在Reverse Linked List的C++提交中击败了14.09% 的用户


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode * ans = new ListNode(0);
        ListNode * tmp2 = head;
        ListNode * tmp = ans->next;
        
        while (tmp2 != NULL) {
            ans->next = tmp2;
            tmp2 = tmp2->next;
            ans->next->next = tmp;
            tmp = ans->next;
        }
        return ans->next;
    }
};

// 递归版本：

// 执行用时 : 12 ms, 在Reverse Linked List的C++提交中击败了97.67% 的用户
// 内存消耗 : 9.4 MB, 在Reverse Linked List的C++提交中击败了5.08% 的用户

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
          return head;
        } else {
            ListNode * ans1 = reverseList(head->next);
            ListNode * tmp2 = ans1;
            head->next->next = head;
            head->next = NULL;
            return ans1;
        }
        return NULL; 
    }
};