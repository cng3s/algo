class CustomStack {
private:
    vector<int> _mystack;
    int _maxSize;

public:
    CustomStack(int maxSize)
        : _maxSize(maxSize) {
    }
    
    void push(int x) {
        if (_mystack.size()+1 > _maxSize) {
            return;
        }
        _mystack.push_back(x);
    }
    
    int pop() {
        if (_mystack.size() == 0) {
            return -1;
        }
        int ret = _mystack.back();
        _mystack.pop_back();
        return ret;
    }
    
    void increment(int k, int val) {
        int limit = k;
        if (limit > _mystack.size()) {
            limit = _mystack.size();
        }
        
        for (int i = 0; i < limit; ++i) {
            _mystack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */