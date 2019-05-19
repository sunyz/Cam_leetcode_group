/**
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
执行用时 : 40 ms, 在Min Stack的C++提交中击败了96.90% 的用户
内存消耗 : 17 MB, 在Min Stack的C++提交中击败了45.21% 的用户
就是在stack之外维护一个最小值。
*/
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s_;
    vector<int> min_;
    MinStack() {
        min_.push_back(INT_MAX);
    }
    
    void push(int x) {
        s_.push(x);
        if (x <= min_[min_.size() - 1])
            min_.push_back(x);
    }
    
    void pop() {
        int a = s_.top();
        s_.pop();
        if (a == min_[min_.size() - 1])
            min_.pop_back();
    }
    
    int top() {
        return s_.top();
    }
    
    int getMin() {
        return min_[min_.size() - 1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
