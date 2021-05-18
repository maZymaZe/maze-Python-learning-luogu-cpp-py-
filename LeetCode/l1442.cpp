class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int l=arr.size();
        vector<int> px(l+1);
        int ans = 0;
        for (int i=1;i<=l;i++)px[i]=px[i-1]^arr[i-1];
        for(int i=0;i<=l;i++){
            for(int j=i+2;j<=l;j++){
                if(px[i]==px[j])ans+=j-i-1;
            }
        }
        return ans;
    }
};