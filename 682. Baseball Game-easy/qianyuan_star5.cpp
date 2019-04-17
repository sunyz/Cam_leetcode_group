// 这个题目考察的是栈，但写起来很罗嗦，就当是熟悉栈的接口了
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        int result = 0;
        for(int i = 0; i < ops.size(); i++) {
            if (ops[i] == "C") {
                int score = s.top();
                s.pop();
                result -= score;
            } else if (ops[i] == "D") {
                int score = s.top();
                s.push(2 * score);
                result += 2 * score;
            } else if (ops[i] == "+") {
                int score1 = s.top();
                s.pop();
                int score2 = s.top();
                s.push(score1);
                s.push(score1 + score2);
                result += score1 + score2; 
            } else {
                int score = atoi(ops[i].c_str());
                s.push(score);
                result += score;
            }
        }
        return result;
    }
};