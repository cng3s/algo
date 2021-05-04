// 执行用时：20 ms, 在所有 C++ 提交中击败了92.14% 的用户
// 内存消耗：15.6 MB, 在所有 C++ 提交中击败了5.02% 的用户

class MinStack {
private:
    stack<int> s;
    multiset<int> nums;

public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        s.emplace(x);
        nums.emplace(x);
    }
    
    void pop() {
        int x = s.top();
        s.pop();
        auto numsIt = nums.find(x);
        if (numsIt != nums.end()) { nums.erase(numsIt); }
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return *nums.cbegin();
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