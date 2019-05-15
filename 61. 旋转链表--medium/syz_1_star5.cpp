/*
 * @Author: sunyz
 * @Date: 2019-05-15 22:23:18
 * @LastEditors: sunyz
 * @LastEditTime: 2019-05-15 22:59:18
 */

//  * @Description: 又是暴力解法
//  * 不过测试时间不稳定。。大多数都是ok的
//  * 遍历一遍，存进vector，然后计算偏移从vector中访问
//  * 参考解法中基本都是改成循环链表。。。不过感觉这样会改输入，所以我
//  * 没有采用那种方法

// 执行用时 : 12 ms, 在Rotate List的C++提交中击败了98.46% 的用户
// 内存消耗 : 9.3 MB, 在Rotate List的C++提交中击败了74.17% 的用户

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> tmp;
        ListNode* it = head;
        while(it != NULL) {
            tmp.push_back(it->val);
            it = it->next;
        }
        int cnt = tmp.size();
        if (cnt == 0) return NULL;
        ListNode* ans = new ListNode(tmp[(cnt - k % cnt) % cnt]);
        ListNode* a = ans;
        for (int i=1; i<cnt; i++) {
            ListNode* ans_one = new ListNode(tmp[(cnt + i - k % cnt) % cnt]);
            a->next = ans_one;
            a = ans_one;
        }
        return ans;
    }
};