class MyHashSet {
public:
    /** Initialize your data structure here. */
    list<int> bi[1000000];
    MyHashSet() {

    }
    
    void add(int key) {
        if(contains(key))return;
        bi[key%1000000].push_back(key);
    }
    
    void remove(int key) {
        int t=key%1000000;
        for(auto p=bi[t].begin(); p!=bi[t].end();p++){
            if(*p==key){
                bi[t].erase(p); return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int t=key%1000000;
        for(auto p=bi[t].begin(); p!=bi[t].end();p++){
            if(*p==key){
                return 1;
            }
        }
        return 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */