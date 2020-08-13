class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ret=0,l=nums.size();
        if(l<2)return ret;
        int pre=-1,c[2]={0};
        vector<int> ct,f;
        for(int i:nums){
            if(i!=pre){
                if(pre!=-1){
                    ct.push_back(c[pre]);
                    f.push_back(pre);
                    c[pre]=0;
                }
                pre=i;
                c[i]=1;
            }else c[i]++;
        }
        ct.push_back(c[pre]);
        f.push_back(pre);
        l=f.size();
        for(int i=0;i<l;i++){
            if(f[i]==1&&ct[i]>ret)ret=ct[i];
            else if(f[i]==0&&ct[i]==1){
                int tmp=0;
                if(i>0)tmp+=ct[i-1];
                if(i+1<l)tmp+=ct[i+1];
                if(tmp>ret)ret=tmp;
            }
        }
        if(l==1&&f[0]==1)return ct[0]-1;
        return ret;
    }
};