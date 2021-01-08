class Solution {
public:
    int a[100002]={0},b[100002]={0};
    int maxEqualFreq(vector<int>& nums) {
        int n=0,ma=0,ans=0;
        for(int i=0;i<nums.size();i++){
            int cur=nums[i];
            if(a[cur]==0)n++;
            a[cur]++;
            ma=max(ma,a[cur]);
            b[a[cur]]++;
            if(a[cur]>1)b[a[cur]-1]--;
            if(ma==1||b[1]==n||(b[ma]==1&&b[ma-1]==n-1)||(b[ma]==n-1&&b[1]==1)){
                ans=i+1;
            }
           
        } return ans;
    }
};