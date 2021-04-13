class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int cnt=0,dg[40],t=label;
        while(t){
            dg[++cnt]=t&1;
            t>>=1;
        }
        vector<int> ans;
        for(int i=cnt;i>0;i--){
            ans.push_back(label);
            label=(1<<i)-(label-(1<<(i-1)))-1;
            label>>=1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};