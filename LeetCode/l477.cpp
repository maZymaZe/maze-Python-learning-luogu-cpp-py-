class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int l=nums.size(),p,c[40]= {0},ans=0,t;
        for(int i=0;i<l;i++){
            t=nums[i];
            p=0;
            while(t){
                c[++p]+=(t&1);
                t>>=1;
            }
        }
        for(int i=0;i<33;i++)ans+=c[i]*(l-c[i]);
        return ans;
    }
};