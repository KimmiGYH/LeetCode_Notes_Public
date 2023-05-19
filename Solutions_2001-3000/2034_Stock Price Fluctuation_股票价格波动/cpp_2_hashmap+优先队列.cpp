class StockPrice {
    using PII = pair<int, int>;
public:
    unordered_map<int, int> hash; //timestamp: price
    priority_queue<PII, vector<PII>> pqmax; //{price, timestamp}
    priority_queue<PII, vector<PII>, greater<PII>> pqmin;
    int maxtime;
    
    StockPrice() {
        this->maxtime = 0;
    }
    
    void update(int timestamp, int price) {
        maxtime = max(maxtime, timestamp);
        hash[timestamp] = price;
        pqmax.emplace(price, timestamp);
        pqmin.emplace(price, timestamp);
    }
    
    int current() {
        return hash[maxtime];
    }
    
    int maximum() {
        while (true) {
            auto t = pqmax.top();
            int price = t.first, timestamp = t.second;
            if (hash[timestamp] == price) return price;
            pqmax.pop();
        }
    }
    
    int minimum() {
        while (true) {
            auto t = pqmin.top();
            int price = t.first, timestamp = t.second;
            if (hash[timestamp] == price) return price;
            pqmin.pop();
        }
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */