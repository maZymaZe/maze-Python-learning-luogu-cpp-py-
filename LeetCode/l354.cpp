class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),cmp);
        vector<int> q;
        int l=envelopes.size();
        for(int i=0; i<l;i++){
            if(q.empty()||q.back()<envelopes[i][1]){
                q.push_back(envelopes[i][1]);
            }else {
                int pos=lower_bound(q.begin(),q.end(),envelopes[i][1])-q.begin();
                q[pos]=envelopes[i][1];
            }
        }
        return q.size();
    }
};