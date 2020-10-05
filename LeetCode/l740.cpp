class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int cnt[10002]={0},pre1=0,pre2=0,tmp;
        for(int &i:nums)cnt[i]++;
        for(int i=1;i<=10000;i++){
            tmp=pre1;
            pre1=max(pre1,pre2+cnt[i]*i);
            pre2=tmp;
        }
        return max(pre1,pre2);
    }
};