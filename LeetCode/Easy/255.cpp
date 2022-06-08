// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：6.7 MB, 在所有 C++ 提交中击败了20.45%的用户

class MyStack {
public:
    MyStack() {
        cur = &q1;
        next = &q2;
    }
    
    void push(int x) {
        cur->push(x);
    }
    
    int pop() {
        //::assert(!cur->empty());
        int x = cur->back();
        while (cur->size() != 1) {
            next->push(cur->front());
            cur->pop();
        }
        cur->pop();
        swap(cur, next);
        return x;
    }
    
    int top() {
        //::assert(!cur->empty());
        return cur->back();
    }
    
    bool empty() {
        return cur->empty();
    }


private:
    queue<int> q1;
    queue<int> q2;
    queue<int> *cur;
    queue<int> *next;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */