#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        monarch = kingName;
    }
    
    void birth(string parentName, string childName) {
        hash[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead[name] = true;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        dfs(monarch, res);
        return res;
    }
    
private:
    void dfs(string name, vector<string> &res) {
        if (!dead[name])  res.push_back(name);
        
        for (string child : hash[name])
            dfs(child, res);
    }
    
private:
    string monarch;
    unordered_map<string, bool> dead;
    unordered_map<string, vector<string>> hash;
};


/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */