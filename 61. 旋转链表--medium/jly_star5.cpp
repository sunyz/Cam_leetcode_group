/**
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
示例 1:
输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:
输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL

执行用时 : 16 ms, 在Rotate List的C++提交中击败了97.15% 的用户
内存消耗 : 8.9 MB, 在Rotate List的C++提交中击败了80.63% 的用户
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
        int len = 1;
        // get the length and the last element
        ListNode* last = head;
        while (last->next) {
            last = last->next;
            len++;
        }
        //cout << "lenth is" << len << endl;
        if (len < 2)
            return head;
        k = k % len;
        if (k == 0)
            return head;
        ListNode* p = head;
        for (int i = 0; i < len - k - 1; i++) {
            p = p->next;
        }
        //cout << p->val;
        ListNode* ret = p->next;
        p->next = NULL;
        last->next = head;
        return ret;
        
    }
};
