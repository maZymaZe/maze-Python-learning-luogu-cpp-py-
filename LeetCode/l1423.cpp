class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l=cardPoints.size();
        int ls[100003]={0},rs[100003]={0},ans=0;
        for(int i=1;i<=k;i++) {
            ls[i]=ls[i-1]+cardPoints[i-1];
            rs[i]=rs[i-1]+cardPoints[l-i];
        }
        for(int i=0;i<=k;i++){
            ans=max(ans,ls[i]+rs[k-i]);
        }
        return ans;
    }
};