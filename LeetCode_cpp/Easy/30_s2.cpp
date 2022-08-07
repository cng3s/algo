// 执行用时：24 ms, 在所有 C++ 提交中击败了71.71% 的用户
// 内存消耗：14.7 MB, 在所有 C++ 提交中击败了36.73% 的用户

class MinStack {
private:
    stack<int> nums, helper;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if (helper.empty() || x <= helper.top()) { helper.emplace(x); }
        nums.emplace(x);
    }
    
    void pop() {
        if (nums.empty()) return;
        int x = nums.top();
        if (x == helper.top()) { helper.pop(); }
        nums.pop();
    }
    
    int top() {
        return nums.top();
    }
    
    int min() {
        if (!helper.empty()) return helper.top();
        return nums.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */