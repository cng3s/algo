// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：6.9 MB, 在所有 C++ 提交中击败了18.35%的用户

class MyQueue {
public:
    MyQueue() {
        cur = &s1;
        next = &s2;
    }
    
    void push(int x) {
        cur -> push(x);
    }
    
    int pop() {
        while (cur->size() != 1) {
            next->push(cur->top());
            cur->pop();
        }
        int e = cur->top();
        cur->pop();
        while (!next->empty()) {
            cur->push(next->top());
            next->pop();
        }
        return e;
    }
    
    int peek() {
        while (cur->size() != 1) {
            next->push(cur->top());
            cur->pop();
        }
        int e = cur->top();
        while (!next->empty()) {
            cur->push(next->top());
            next->pop();
        }
        return e;
    }
    
    bool empty() {
        return cur->empty();
    }

private:
    stack<int> s1;
    stack<int> s2;

    stack<int> *cur;
    stack<int> *next;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */