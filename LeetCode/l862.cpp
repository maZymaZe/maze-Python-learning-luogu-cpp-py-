class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int l=A.size();
        vector<int> ps(l+2),pos,val;
        for(int i=0;i<l;i++)ps[i+1]=ps[i]+A[i];
        pos.push_back(0);
        val.push_back(0);
        for(int i=1;i<=l;i++){
            if(ps[i]>val.back()){
                val.push_back(ps[i]);
                pos.push_back(i);
            }
        }
        int ans=0x3f3f3f3f,pp=0;
        for(int i=0;i<l;i++){
            if(i==pos[pp])pp++;
            if(pp==pos.size()){
                break;
            }
            auto prs=lower_bound(val.begin()+pp,val.end(),ps[i]+K);
            if(prs==val.end())continue;
            int idx=prs-val.begin();
            ans=min(ans,pos[idx]-i); 
            
        }
        if(ans==0x3f3f3f3f)ans=-1;
        return ans;
    }
};