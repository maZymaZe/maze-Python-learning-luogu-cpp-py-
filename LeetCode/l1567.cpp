class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int lp=0,ln=0,mlp=0,l=nums.size();
        lp=nums[0]>0?1:0;
        ln=nums[0]<0?1:0;
        mlp=lp;
        for(int i=1;i<l;i++){
            if(nums[i]==0){
                lp=ln=0;
            }else if(nums[i]>0){
                lp++;
                ln=ln?ln+1:0;
            }else{
                int t=ln;
                ln=lp+1;
                lp=t?t+1:0;
            }
            mlp=max(mlp,lp);
        }
        return mlp;
    }
};