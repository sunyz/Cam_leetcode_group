/**
编写一个程序，找到两个单链表相交的起始节点。
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 执行用时 : 56 ms, 在Intersection of Two Linked Lists的C++提交中击败了97.55% 的用户
内存消耗 : 20.5 MB, 在Intersection of Two Linked Lists的C++提交中击败了5.09% 的用户
unordered_map里那个int，我不知道怎么去掉。。
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * p1 = headA;
        ListNode * p2 = headB;
        unordered_map<ListNode*, int> m;
        while(p1) {
            m.insert(pair<ListNode*, int>(p1, 1));
            p1 = p1->next;
        }
        while (p2) {
            if (m.count(p2)) {
                return p2;
            }
            p2 = p2->next;
        }
        return nullptr;
    }
};
