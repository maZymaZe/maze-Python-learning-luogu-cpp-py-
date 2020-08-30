bool cmp(const vector<int>& a, const vector<int>& b){
    if(a[0]<b[0])return 1;
    else if(a[0]==b[0]&&a[1]<b[1])return 1;
    return 0;
}
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> ans;
        int l=intervals[0][0],r=intervals[0][1],len=intervals.size();
        for(int i=1;i<len;i++) {
            if(intervals[i][0]<=r)r=max(intervals[i][1],r);
            else {
                ans.push_back({l,r});
                l=intervals[i][0];r=intervals[i][1];
            }
        }
        ans.push_back({l,r});
        return ans;
    }
};