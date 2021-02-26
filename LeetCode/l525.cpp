class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int l=nums.size(),ans=0;
        vector<int> s(2*l+1),t(2*l+1);
        int b=l;

        for(int i=0; i<l;i++){
            b+=(nums[i]==1)?1:-1;
            s[b]=i+1;
            if(t[b]==0)t[b]=i+1;
            if(s[b]-t[b]+1>ans)ans=s[b]-t[b];
        }
        ans=max(ans,s[l]);
        return ans;
    }
};