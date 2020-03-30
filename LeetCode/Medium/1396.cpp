// 执行用时 :680 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗 :60.6 MB, 在所有 C++ 提交中击败了100.00%的用户

class UndergroundSystem {
private:
    typedef struct _record_entry {
        int times; // 搭乘次数
        double aver; // 平均时间
        _record_entry(int t, double a) : times(t), aver(a) {}
    } _record_entry;

    unordered_map<int, pair<string, int>> _running_record; // key: id, value: <from, start_time>
    unordered_map<string, _record_entry*> _record; // key: from_to, value: _record_entry

public:
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        _running_record.insert( { id, {stationName, t} } );
    }
    
    void checkOut(int id, string stationName, int t) {
        auto running_record_it = _running_record.find(id);

        if (_running_record.end() == running_record_it) { // handle argument exception
            return;
        }

        // do something
        string str = running_record_it->second.first + "_" + stationName; // str: from_to
        auto record_it = _record.find(str);
        double timestamp = t - running_record_it->second.second;

        if (record_it != _record.end()) { // do update
            _record_entry *entry = record_it->second;
            double tot = double(entry->times) * entry->aver + timestamp;
            ++entry->times;
            entry->aver = tot / double(entry->times);
        } else { // do insert
            _record_entry *entry = new _record_entry( 1, timestamp );
            _record.insert( {str, entry} );
        }

        _running_record.erase(running_record_it);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto it = _record.find(startStation + "_" + endStation);
        return it != _record.end() ? it->second->aver : 0.0;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */