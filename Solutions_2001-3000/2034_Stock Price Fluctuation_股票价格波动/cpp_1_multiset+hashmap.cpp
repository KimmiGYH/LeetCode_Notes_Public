class StockPrice {
public:
    multiset<int> mst; //prices
    unordered_map<int, int> hash; //timestamp:price
    int maxtime;
    
    StockPrice() {
        this->maxtime = 0;
    }
    
    void update(int timestamp, int price) {
        if (hash.count(timestamp))
            mst.erase(mst.find(hash[timestamp]));
        hash[timestamp] = price;
        mst.insert(price);
        maxtime = max(maxtime, timestamp);
    }
    
    int current() {
        return hash[maxtime];
    }
    
    int maximum() {
        return *mst.rbegin();
    }
    
    int minimum() {
        return *mst.begin();        
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