/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

我先想到的错误解法：分治，n的结果由n-1的结果推出：
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<string> res;
        if (n == 0)
            return res;
        else if (n == 1) {
            res.push_back("()");
            return res;
        } else {
            std::vector next = generateParenthesis(n-1);
            for (int i = 0; i < next.size(); i++) {
                res.push_back("()" + next[i]);
                res.push_back("("+next[i] + ")");
                cout << next[i][1];
                if ((char)next[i][1] == char('(')) {
                    res.push_back(next[i] + "()");
                    //cout << "a";
                }
                    
            }
            return res;
        }
    }
};
但其实并不是这样的，例如n=4时结果中的(())(())就不能由n=3的结果推出，所以最后还是要参考答案。
正确做法：*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<string> res;
        gen_DFS("", n, n, res);
        return res;
    }
    
    void gen_DFS(string curr, int left, int right, std::vector<string> &res) {
        if (left > right)
            return;
        if (left == 0 && right == 0)
            res.push_back(curr);
        
        if (left > 0) gen_DFS(curr+"(", left - 1, right, res);
        if (right > 0) gen_DFS(curr+")", left, right - 1, res);
        
    }
};
