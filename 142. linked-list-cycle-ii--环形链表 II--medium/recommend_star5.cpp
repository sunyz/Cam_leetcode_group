看完忍不住分享
神仙解法！

执行用时 : 12 ms, 在Linked List Cycle II的C++提交中击败了98.89% 的用户
内存消耗 : 9.7 MB, 在Linked List Cycle II的C++提交中击败了59.68% 的用户

o(n)算法，应该是最快的。 堆的地址从低到高，LeetCode的链表内存是顺序申请的，如果有环，head->next一定小于head，哈哈哈哈哈

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        while(head) {
            if(!less<ListNode *>()(head, head->next)) {
                return head->next;
            }
            head = head->next;
        }
        return nullptr;
    }
};