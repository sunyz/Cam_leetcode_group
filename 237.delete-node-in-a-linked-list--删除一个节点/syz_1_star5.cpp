/*
 * @Author: sunyz
 * @LastEditors: sunyz
 * @Date: 2019-05-11 23:13:45
 * @LastEditTime: 2019-05-11 23:15:52
 */

//  * @Description: 一个垃圾题
//  * 强行转换实现思维。难点在于读题
//  * 主要是
//  * 这种做法毫无安全性啊。。。
//  * 而且解法唯一。。

// 执行用时 : 20 ms, 在Delete Node in a Linked List的C++提交中击败了97.18% 的用户
// 内存消耗 : 9.3 MB, 在Delete Node in a Linked List的C++提交中击败了5.55% 的用户

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
    void deleteNode(ListNode* node) {
        //cout << node->val<<endl;
        node->val = node->next->val;
        //cout << node->val<<endl;
        node->next = node->next->next;
    }
};