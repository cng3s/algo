// 执行用时：612 ms, 在所有 C++ 提交中击败了8.82% 的用户
// 内存消耗：108.4 MB, 在所有 C++ 提交中击败了15.10% 的用户

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
        if (appendStack.empty()) {
            return -1;
        }

        while (!appendStack.empty()) {
            deleteStack.push(appendStack.top());
            appendStack.pop();
        }

        int ans = deleteStack.top();
        deleteStack.pop();
        
        while (!deleteStack.empty()) {
            appendStack.push(deleteStack.top());
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