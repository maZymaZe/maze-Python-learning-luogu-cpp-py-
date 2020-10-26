class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int l=customers.size(),ans=0;
        vector<int> s(l+2);
        for(int i=0;i<l;i++){
            if(!grumpy[i])ans+=customers[i],customers[i]=0;
            s[i+1]=s[i]+customers[i];
        }
        if(X>=l)return ans+s[l];
        int ma=-1;
        for(int i=X;i<=l;i++){
            if(s[i]-s[i-X]>ma)ma=s[i]-s[i-X];
        }
        return ma+ans;
    }
};