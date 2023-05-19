#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class ThroneInheritance {
private:
    class Node {
    public:
        Node(const string& name_)
            : name(name_), dead(false) {                
        }
        
        string name;
        vector<Node*> children;
        bool dead;
    };
    
public:
    ThroneInheritance(string kingName)
        : monarch(nullptr) {
        monarch = new Node(kingName);
        hash[kingName] = monarch;        
    }
    
    void birth(string parentName, string childName) {
        Node* node = new Node(childName);
        hash[childName] = node;
        hash[parentName]->children.push_back(node);        
    }
    
    void death(string name) {
        hash[name]->dead = true;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        dfs(monarch, res);
        return res;
    }

private:
    Node* monarch;
    unordered_map<string, Node*> hash;
    
    void dfs(Node* root, vector<string>& res) {//preorder
        if (!root) return;        
        if (!root->dead) res.push_back(root->name);
        
        for (Node* child : root->children)
            dfs(child, res);
    }    
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */