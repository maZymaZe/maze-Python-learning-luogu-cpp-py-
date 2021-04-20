class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int l=nums.size();
        long long ans=0,MOD=1e9+7;
        vector<long long> ps(l+1);
        for (int i=1;i<=l;i++)ps[i]=ps[i-1]+nums[i-1];
        for(int i=1;i<=l-2;i++){
            long long lf=ps[i];
            long long rs=ps[l]-lf;
            if(rs<lf*2)break;
            long long mxl=rs/2;
            long long mil=lf;
            auto t2=lower_bound(ps.begin()+i+1,ps.begin()+l,lf+mxl+1);
            if(t2!=ps.begin()+1+i)t2--;
            else continue;
            auto t1=lower_bound(ps.begin()+i+1,ps.begin()+l,lf+lf);
            if(t1>t2)continue;
            ans=(ans+(t2-t1)+1)%MOD;
        }
        return ans;
    }
};