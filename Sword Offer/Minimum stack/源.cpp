//最小栈
class Solution {
public:
    stack<int> s,data;
    void push(int value) {
        data.push(value);
        if(s.empty()||s.top()>value)
            s.push(value);
        else
            s.push(s.top());
    }
    void pop() {
        if(s.empty()&&data.empty())
            return;
        data.pop();
        s.pop();
    }
    int top() {
        return data.top();
    }
    int min() {
        return s.top();
    }
};