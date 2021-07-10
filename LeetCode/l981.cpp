struct pr{
    int tsp;
    string v;
    bool operator <(const pr& x)const{
        return tsp<x.tsp;
    }
};
class TimeMap {
public:
    unordered_map<string,vector<pr>> mp;
    /** Initialize your data structure here. */
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        if(mp.count(key)){
            mp[key].push_back({timestamp,value});
        }else{
            mp.insert({key,vector<pr>()});
            mp[key].push_back({timestamp,value});
        }
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key))return "";
        auto& x=mp[key];
        pr t={timestamp,""};
        auto it=upper_bound(x.begin(),x.end(),t);
        if(it==x.begin())return "";
        --it;
        return (*it).v;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */