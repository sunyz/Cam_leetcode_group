/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Date: 2019-04-03 00:20:50
 * @LastEditTime: 2019-04-03 01:10:44
 */

//  * @Description: 这个提交很失败。。。第一反应是用栈来直接实现，并且用switch
//  * 来把string转换成int来方便判断，但是又慢又费时间。。之后一定重新来做这个
//  * 用评论的ascii的方式来替换转换成int的方式作用不大，用iter遍历来替换getsize
//  * 的过程也都没什么效果
//  * 严重怀疑就不应该用stack
//    FIXME: 来日再战

// 执行用时 : 8 ms, 在Valid Parentheses的C++提交中击败了17.41% 的用户
// 内存消耗 : 8.5 MB, 在Valid Parentheses的C++提交中击败了0.93% 的用户

#include <stack>

class Solution {
public:
    bool isValid(string s) {
        int ss = s.size();
        stack<int> st;
        for (int i=0;i<ss;i++) {
            int tmp;
            switch(s[i]) {
                case '(': tmp = 1;break;
                case ')': tmp = -1;break;
                case '[': tmp = 2;break;
                case ']': tmp = -2;break;
                case '{': tmp = 3;break;
                case '}': tmp = -3;break;
            }
            if (tmp > 0) {
                st.push(tmp);
            } else if (st.empty()) {
                return false;
            } else if (tmp + st.top() == 0) {
                st.pop();
            } else {
                return false;
            }
        }
        return st.empty() ? true : false;

    }
};