bool cmp(const vector<int>&a,const vector<int> &b){
    if(a[0]<b[0])return 1;
    if(a[0]==b[0]&&a[1]>b[1])return 1;
    return 0;
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),cmp);
        int head=0,ls,al,ar,p;
        vector<vector<int>> ans;
        while(head<intervals.size()){
            al=intervals[head][0];
            ar=intervals[head][1];
            p=head+1;
            while(p<intervals.size()&&intervals[p][0]<=ar){
                if(intervals[p][1]>ar)ar=intervals[p][1];
                p++;
            }
            vector<int> tmp;
            tmp.push_back(al);
            tmp.push_back(ar);
            ans.push_back(tmp);
            head=p;
        }
        return ans;
    }
};