class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2],mini=abs(ans-target);
        int l=nums.size(),p,q;
        for(int lx=0;lx<l-2;lx++){
            p=lx+1;q=l-1;
            while(p<q){
                int tot=nums[lx]+nums[p]+nums[q];
                int dx=target-tot;
                if(dx==0)return tot;
                if(abs(dx)<mini){
                    mini=abs(dx);
                    ans=tot;
                }
                if(dx>0)p++;
                else if(dx<0)q--;
            }
        }
        return ans;
    }
};