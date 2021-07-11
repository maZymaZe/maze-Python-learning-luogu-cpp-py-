struct pr{
    int frq,pos,val;
    bool operator <(const pr& x)const {
        return !(frq>x.frq||(frq==x.frq&&pos>x.pos));
    }
};
class FreqStack {
public:
    unordered_map<int,int> mp;
    int sz=0;
    priority_queue<pr> pq;
    FreqStack() {
        sz=0;
        mp.clear();
        while(!pq.empty())pq.pop();
    }
    
    void push(int val) {
        mp[val]++;
        sz++;
        pq.push((pr){mp[val],sz,val});
    }
    
    int pop() {
        auto t=pq.top();
        pq.pop();
        mp[t.val]--;
        return t.val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */