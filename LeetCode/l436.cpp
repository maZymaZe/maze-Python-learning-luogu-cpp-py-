bool cmp(const vector<int>& a, const vector<int> & b){
    return a[0]< b[0];
}
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int l=intervals.size();
        for(int i=0; i<l;i++)intervals[i].push_back(i);
        sort(intervals.begin(), intervals.end(),cmp);
        vector<int> t,ans(l);
        t.push_back(0);
        for(int i=0; i<l; i++){
            t[0]=intervals[i][1];
            auto it=lower_bound(intervals.begin(), intervals.end(), t,cmp);
            if(it==intervals.end())ans[intervals[i][2]]=-1;
            else ans[intervals[i][2]]=(*it)[2];
        }
        return ans;
    }
};