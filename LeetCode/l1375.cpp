class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int ma=-1,l=light.size(),ans=0;
        for(int i=0;i<l;i++){
            ma=max(ma,light[i]);
            if(ma==i+1)ans++;
        }
        return ans;
    }
};