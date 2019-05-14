/*
 * @Author: sunyz
 * @Date: 2019-05-13 20:07:33
 * @LastEditors: sunyz
 * @LastEditTime: 2019-05-14 10:11:12
 */

//  * @Description: 这个需要借助画图理解会快很多
//  当用2倍速的时候，快慢指针相遇在环上某点
//  参见下图
//   A              B      C 
//   %--------------%------%
//                  |      |
//                  |      |
//                  %------%
//                  E      D
//  假设相遇于D点，则快指针应该这时刚好套慢指针一圈（2倍速的必然结果，可以数学证明）
//  则此时快指针走的路程为 'AB + BCDEB + BD' （用BCDEB表示一圈）(字母序表示方向，AB 表示A -> B)
//  慢指针走的路程为 'AB + BD'
//  由于S(快指针) = 2 * S(慢指针) （因为2倍速）（S表示总路程）
//  ==> AB + BCDEB + BD = 2 * (AB + BD)      -----(1)
//  ==> AB + BD = BCDEB                      -----(2)
//  上式表明此时慢指针走过的全部路径刚好一圈
//  我们的目标是获得B点这一入环点
//  又根据一圈的关系 ， 有一圈剩余部分
//  DB = BCDEB - BD                          -----(3)
//  联立式(2)(3)， 有
//  AB = DB                                  -----(4)
//  上式表示D到B的距离和A到B的距离是相等的
//  另一种说法，在慢指针从相遇点D继续向前走DB个长度，一个新指针从A起始点用同样速度
//  开始走，两个指针将会在B点相遇，而B点也正是我们想要的相遇点
 

// 执行用时 : 12 ms, 在Linked List Cycle II的C++提交中击败了98.89% 的用户
// 内存消耗 : 9.6 MB, 在Linked List Cycle II的C++提交中击败了93.51% 的用户

#include <hash_map>
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head;
        ListNode *slow=head;
        bool have_cycle = false;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast && fast==slow){
                have_cycle = true;
                break;
            }
        }
        if (have_cycle) {
            fast = head; // 复用快指针
            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
        return NULL;
        
    }
};