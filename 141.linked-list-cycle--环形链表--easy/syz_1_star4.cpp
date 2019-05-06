/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Date: 2019-05-07 00:21:53
 * @LastEditTime: 2019-05-07 00:38:27
 */

//  * @Description: 快慢指针的标准题
//  * 这个题。。读懂题才是最麻烦的。。看了好久才知道输入时什么意思。。
//  * 判断的话就是用快慢指针，如果有环，则一定会快的追上慢的
//  * 速率这里选的是2倍，测试了一下在输入规模小的情况下，变换
//  * 速率倍数差没有意义
//  * 看了一下参考解答，可以不引入flag更加优雅一点


// 执行用时 : 20 ms, 在Linked List Cycle的C++提交中击败了82.94% 的用户
// 内存消耗 : 9.7 MB, 在Linked List Cycle的C++提交中击败了58.38% 的用户

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode *fast = head;
        ListNode *slow = head;
        int flag = -1;
        while(fast->next != NULL) {
            fast = fast->next;
            if (flag == 1) {
                slow = slow->next;
            }
            flag = -flag;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};

// 更加优雅的写法，同样的思路，无flag

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
    }
};