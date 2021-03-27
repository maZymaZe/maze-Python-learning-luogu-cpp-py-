class MyCalendar {
public:
    map<int,int> mp;
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        if(mp.empty()){
            mp.insert({start,end});
            return true;
        }
        auto it = mp.lower_bound(start);
        if(it==mp.begin()){
            if(end<=mp.begin()->first){
                mp.insert({start,end});
                return true;
            }else return false;
        }
        if(it==mp.end()){
            it--;
            if(it->second>start)return false;
            mp.insert({start,end});
            return true;
        }
        if(end>it->first)return false;
        it--;
        if(start<it->second)return false;
        mp.insert({start,end});
        return true;

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */