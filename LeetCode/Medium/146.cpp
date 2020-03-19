// 执行用时 :364 ms, 在所有 C++ 提交中击败了5.26% 的用户
// 内存消耗 :39.9 MB, 在所有 C++ 提交中击败了55.66%的用户

// LRU - 链表实现
// get - O(n), put - O(n)

class LRUCache {
private:
    list<pair<int, int>> _cache;
    int _capacity;
public:
    LRUCache(int capacity) : _capacity(capacity) {
    }
    
    int get(int key) {
        for (auto it = _cache.begin(); it != _cache.end(); ++it) {
            if (it->first == key) {
                // 更新该节点位置
                int ret = it->second;
                _cache.erase(it);
                _cache.push_front({ key, ret });
                return ret;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {

        // 检查队列中是否有相同的key, 如果有则移除
        for (auto it = _cache.begin(); it != _cache.end(); ++it) {
            if (it->first == key) {
                _cache.erase(it);
                break;
            }
        }

        if (_cache.size() == _capacity) {
            // 淘汰cache中最近最久未使用的
            _cache.pop_back();
        }

        // 添加
        _cache.push_front({ key, value });
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */