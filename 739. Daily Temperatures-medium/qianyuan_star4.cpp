// 执行用时 : 280 ms, 在Daily Temperatures的C++提交中击败了84.99% 的用户
// 内存消耗 : 16 MB, 在Daily Temperatures的C++提交中击败了71.52% 的用户
// 经典的逆序栈问题，中间在c++语法上浪费了很长时间，还是代码写的太少了...
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        unordered_map<int, int> map;
        stack<int> stack;
        for (int i = 0; i < T.size(); i++) {
            while (!stack.empty() && T[stack.top()] < T[i]) {
                T[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }
        while (!stack.empty()) {
            T[stack.top()] = 0;
            stack.pop();
        }
        return T;
    }
};