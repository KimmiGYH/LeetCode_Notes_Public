class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>> > hash;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& pairs = hash[key];
        pair<int, string> p(timestamp + 1, "");
        auto iter = upper_bound(pairs.begin(), pairs.end(), p);
        if (iter != pairs.begin())
            return (iter-1)->second;
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

// ----------------------------------------------------------

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>> > hash;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& pairs = hash[key];
        pair<int, string> p(timestamp + 1, "");
        auto iter = upper_bound(pairs.begin(), pairs.end(), p);
        if (iter == pairs.begin()) return "";
        --iter;
        return iter->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */