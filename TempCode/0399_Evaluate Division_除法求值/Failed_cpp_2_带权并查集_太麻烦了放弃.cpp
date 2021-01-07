#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
/*
    int find(vector<int>& f, vector<double>& w, int x) {
        if (f[x] != x) {
            int father = find(f, w, f[x]);
            w[x] = w[x] * w[f[x]];
            f[x] = father;
        }
        return f[x];
    }

    void merge(vector<int>& f, vector<double>&w, int x, int y, double val) {
        int fx = find(f, w, x);
        int fy = find(f, w, y);
        f[f[x]] = fy;
        w[fx] = val * w[y]/w[x];
    }
*/
    unordered_map<string, pair<string, int>> parents;

    pair<string, double> find(const string& C) {
        if (C != parents[C].first) {
            const auto& father = find(parents[C].first);
            parents[C].second *= father.second;
            parents[C].first = father.first;
        }
        return parents[C];
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // parents["A"] = {"B", 2.0} -> A = 2.0 * B
        // parents["B"] = {"C", 3.0} -> B = 3.0 * C
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            const double k = values[i];

            if (!parents.count(A) && !parents.count(B)) {
                parents[A] = {B, k};
                parents[B] = {B, 1.0};
            } else if (!parents.count(A)) {
                parents[A] = {B, k};
            } else if (!parents.count(B)) {
                parents[B] = {A, 1.0 / k};
            } else {
                // 返回的是一个pair，是节点和它father之间的比值关系
                auto& rA = find(A);
                auto& rB = find(B);
                if (rA != rB) {
                    rA.first = rB.first;
                    rA.second *= (k * rB.second);
                }
            }

        }
        
    }
};