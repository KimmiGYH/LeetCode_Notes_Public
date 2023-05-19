class TopVotedCandidate {
public:
    vector<int> winner;
    vector<int> times;
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        winner.resize(n);
        vector<int> count(n + 1);
        int maxc = -1, maxp = -1;
        for (int i = 0; i < n; i++) {
            int p = persons[i];
            if (++count[p] >= maxc) {
                maxc = count[p];
                maxp = p;
            }
            winner[i] = maxp;
        }
        this->times = times;
    }
    
    int q(int t) {
        int l = 0, r = times.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (times[mid] <= t) l = mid;
            else r = mid - 1;
        }
        return winner[r];
    }
};

// -----------------------------------------------------------
    //用库函数upper_bound
    int q(int t) {
        int pos = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return winner[pos];
    }



/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */