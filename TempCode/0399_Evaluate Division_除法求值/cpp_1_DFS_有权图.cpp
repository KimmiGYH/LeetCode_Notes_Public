#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
/*
输入：
    equations = [["a","b"],["b","c"]], 
    values = [2.0,3.0], 
    queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
输出：[6.00000, 0.50000, -1.00000, 1.00000, -1.00000]
解释：
条件：a / b = 2.0, b / c = 3.0
问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
*/
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // g[A][B] = k  ->  A / B = k
        unordered_map<string, unordered_map<string, double>> g;
        /* g{
                {"a", {"b", 2.0}}, {"b", {"c", 3.0}},
                {"b", {"a", 1/2}}, {"c", {"b", 1/3}}
            };
        */
        for (int i = 0; i < equations.size(); ++i) {
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            const double k = values[i];
            g[A][B] = k;
            g[B][A] = 1.0 / k;
        }

        vector<double> res;
        for (const auto& pair : queries) { // eg.1st pair: ["a","c"]
            const string& X = pair[0];     // X: "a"
            const string& Z = pair[1];     // Z: "c"
            if (!g.count(X) || !g.count(Z)) {
                res.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            res.push_back(divide(X, Z, g, visited));
        }
        return res;
    }
private:
    // get result of X/Z
    double divide(const string& X, const string& Z, 
                  unordered_map<string, unordered_map<string, double>>& g,
                  unordered_set<string>& visited) {
        if (X == Z)  return 1.0;
        visited.insert(X); // visited ["a",]
        for (const auto& pair : g[X]) {   // X: a 
            const string& Y = pair.first; // Y: b
            if (visited.count(Y)) continue;
            double d = divide(Y, Z, g, visited); // d = Y/Z ||即 d=b/c
            // X/Z = Y/Z * X/Y ||即 a/c = b/c * a/b
            if (d > 0)  return d * g[X][Y];
        }
        return -1.0;
    }
};