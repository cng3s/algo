class Solution {
private:
    struct entry {
        int nice;
        int ix;
        int endTime;
        int taskIx;
        entry(int argNice, int argIx) : nice(argNice), ix(argIx), endTime(0), taskIx(0) {}
    };


    struct cmp {
        bool operator()(const shared_ptr<entry>& lhs, const shared_ptr<entry>& rhs) {
            if (lhs->nice != rhs->nice)
                return lhs->nice > rhs->nice;
            return lhs->ix > rhs->ix;
        }  
    };
    
    struct cmp2 {
        bool operator()(const shared_ptr<entry>& lhs, const shared_ptr<entry>& rhs) {
            return lhs->endTime > rhs->endTime;
        }
    };

public:

    priority_queue<shared_ptr<entry>, vector<shared_ptr<entry>>, cmp> idle;
    priority_queue<shared_ptr<entry>, vector<shared_ptr<entry>>, cmp2> busy;
    

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    
        vector<int> ans(tasks.size(), 0);
        
        for (int i = 0; i < servers.size(); ++i) {
            idle.emplace(make_shared<entry>(entry(servers[i], i)));
        }
        
        int curTime = 0;
        for (int i = 0; i < tasks.size(); ++i) {
            curTime = max(curTime, i);
            while (!busy.empty() && busy.top()->endTime <= curTime) {
                idle.emplace(busy.top());
                busy.pop();
            }
            if (idle.empty()) {
                curTime = busy.top()->endTime;
                while (!busy.empty() && busy.top()->endTime == curTime) {
                    idle.emplace(busy.top());
                    busy.pop();
                }
            }
            
            const auto idlePtr = idle.top();
            idle.pop();
            idlePtr->endTime = curTime + tasks[i];
            idlePtr->taskIx = i;
            busy.emplace(idlePtr);
            ans[i] = idlePtr->ix;     
        }
        
        
        return ans;
    }
};