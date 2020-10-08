class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans=0,l=-1,r=-2,len=timeSeries.size();
        sort(timeSeries.begin(),timeSeries.end());
        for(int i=0; i<len; i++) {
            if(timeSeries[i]>r){
                ans+=r-l+1;
                l=timeSeries[i],r=timeSeries[i]+duration-1;
            }else{
                r=timeSeries[i]+duration-1;
            }
        }
        ans+=r-l+1;
        return ans;
    }
};