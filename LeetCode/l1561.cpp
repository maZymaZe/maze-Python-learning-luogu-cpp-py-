class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n=piles.size()/3,ans=0;
        for(int i=0,p=n;i<n;i++,p+=2)ans+=piles[p];
        return ans;
    }
};