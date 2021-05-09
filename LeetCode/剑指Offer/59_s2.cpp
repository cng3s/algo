// 执行用时：132 ms, 在所有 C++ 提交中击败了82.39% 的用户
// 内存消耗：47.4 MB, 在所有 C++ 提交中击败了95.46% 的用户

class MaxQueue {
private:
    queue<int> q;
    deque<int> d;
public:
    MaxQueue() {

    }
    
    int max_value() {
        if (q.empty()) { return -1; }
        return d.front();
    }
    
    void push_back(int value) {
        while (!d.empty() && value > d.back()) {
            d.pop_back();
        }
        d.emplace_back(value);
        q.emplace(value);
    }
    
    int pop_front() {
        if (q.empty()) { return -1; }
        int x = q.front();
        if (x == d.front()) { d.pop_front(); }
        q.pop();
        return x;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */