class Solution {
public:
    int n,ans=0,lm,rm,l1,l2,r1,r2;
    vector<int> sum;
    int waysToMakeFair(vector<int>& nums) {
        n=nums.size();
        sum.resize(n+5);
        for(int i=0;i<n;i++){
            sum[i+2]=sum[i]+nums[i];
        }
        
        for(int i=0;i<n;i++){ 
            l1=i;r1=i+1;
            l2=i+1;r2=i+2;
            if(i&1){               
                if(n&1)lm=n+1,rm=n;
                else lm=n,rm=n+1;
            }else{
                if(n&1)lm=n,rm=n+1;
                else lm=n+1,rm=n;
            }
            if(sum[lm]-sum[l2]+sum[l1]==sum[rm]-sum[r2]+sum[r1])ans++;           
        }
        return ans;
    }
};