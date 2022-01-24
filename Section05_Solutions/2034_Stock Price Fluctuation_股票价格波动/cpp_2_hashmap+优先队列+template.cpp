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
    
    template<typename T>
    void update_heap(const PII& stock, T& pq) {
        pq.push(stock);
        while (hash[pq.top().second] != pq.top().first)
            pq.pop();
    }
    
    void update(int timestamp, int price) {
        PII cur = {price, timestamp};
        maxtime = max(maxtime, timestamp);
        hash[timestamp] = price;
        
        update_heap(cur, pqmax);
        update_heap(cur, pqmin);
    }
    
    int current() {
        return hash[maxtime];
    }
    
    int maximum() {
        return pqmax.top().first;
    }
    
    int minimum() {
        return pqmin.top().first;
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