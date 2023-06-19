class Solution {
private:
    stack<int> stdate;
    stack<int> stmin;

public:
    void push(int value) {
        if (stmin.empty() || stmin.top() > value)
        {
            stmin.push(value);
        }
        else
        {
            stmin.push(stmin.top());
        }
        stdate.push(value);
    }
    void pop() {
        stdate.pop();
        stmin.pop();
    }
    int top() {
        return stdate.top();
    }
    int min() {
        return stmin.top();
    }
};