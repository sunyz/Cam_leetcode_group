// 执行用时 : 8 ms, 在Remove Outermost Parentheses的C++提交中击败了99.71% 的用户
// 内存消耗 : 9 MB, 在Remove Outermost Parentheses的C++提交中击败了47.84% 的用户
// 经典的括号题目，都是套路
class Solution {
public:
    string removeOuterParentheses(string S) 
    {
        string results;
        int flag=0;
        for(char c:S)
        {
            if(c == '(' && flag++ >0)
                results += c;
            if(c == ')' && flag-- >1)
                results +=c;
        }
        return results;
    }
};