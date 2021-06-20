class ThroneInheritance {
public:
    unordered_map<string,vector<string>> edges;
    unordered_set<string> dead;
    string king;
    ThroneInheritance(string kingName) {
        king= kingName;
    }
    
    void birth(string parentName, string childName) {
        edges[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        function<void(const string&)> preoder=[&](const string& name){
            if(!dead.count(name)){
                ans.push_back(name);
            }
            if(edges.count(name)){
                for(const auto&ch:edges[name]){
                    preoder(ch);
                }
            }
        };
        preoder(king);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */