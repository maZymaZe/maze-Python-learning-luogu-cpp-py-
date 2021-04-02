class Solution {
public:
    int trap(vector<int>& height) {
        int len=height.size();
        int l=0,r=len-1;
        while(l+1<len&&height[l]<=height[l+1])l++;
        while(r-1>=0&&height[r-1]>=height[r])r--;
        if(l>r)return 0;
        vector<int> lm(len),rm(len);
        lm[l]=height[l],rm[r]=height[r];
        for(int i=l+1;i<=r;i++)lm[i]=max(lm[i-1],height[i]);
        for(int i=r-1;i>=l;i--)rm[i]=max(rm[i+1],height[i]);
        int ans=0;
        for(int i=l;i<=r; i++)ans+=max(min(lm[i],rm[i])-height[i],0);
        return ans;
    }
};