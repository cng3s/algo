// 执行用时：148 ms, 在所有 C++ 提交中击败了38.17% 的用户
// 内存消耗：50.4 MB, 在所有 C++ 提交中击败了5.01% 的用户

class MaxQueue {
private:
    multiset<int, greater<int>> s;
    queue<int> q;
public:
    MaxQueue() {

    }
    
    int max_value() {
        if (q.empty()) { return -1; }
        return *s.cbegin();
    }
    
    void push_back(int value) {
        q.emplace(value);
        s.emplace(value);
    }
    
    int pop_front() {
        if (q.empty()) { return -1; }
        int x = q.front();
        q.pop();
        auto sIt = s.find(x);
        s.erase(sIt);
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