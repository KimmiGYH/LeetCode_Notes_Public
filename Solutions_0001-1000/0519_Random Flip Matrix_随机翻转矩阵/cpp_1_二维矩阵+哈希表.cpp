class Solution {
public:
    unordered_set<int> hash;
    int rows, cols, capacity;

    Solution(int m, int n) {
        rows = m;
        cols = n;
        capacity = rows * cols;
    }
    
    vector<int> flip() {
        int pos = rand() % capacity;
        while (hash.count(pos)) { //哈希表记录过
            pos++;
            pos %= capacity;
        }
        hash.insert(pos);
        return {pos / cols, pos % cols};
    }
    
    void reset() {
        hash.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */