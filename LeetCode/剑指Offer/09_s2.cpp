// 执行用时：316 ms, 在所有 C++ 提交中击败了86.65% 的用户
// 内存消耗：100.9 MB, 在所有 C++ 提交中击败了99.30% 的用户

class CQueue {
private:
    stack<int> appendStack, deleteStack;

public:
    CQueue() {

    }
    
    void appendTail(int value) {
        appendStack.emplace(value);
    }
    
    int deleteHead() {
        if (deleteStack.empty()) {
            while (!appendStack.empty()) {
                deleteStack.emplace(appendStack.top());
                appendStack.pop();
            }
        }

        int ans = -1;
        if (!deleteStack.empty()) {
            ans = deleteStack.top();
            deleteStack.pop();
        }
        return ans;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */