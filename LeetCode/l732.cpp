class MyCalendarThree {
public:
    MyCalendarThree() {

    }
    map<int, int> mp;
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int t=0,ans=0;
        for(auto i:mp)t+=i.second,ans=max(ans,t);
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */