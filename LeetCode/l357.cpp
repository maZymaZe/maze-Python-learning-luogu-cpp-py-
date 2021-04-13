class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int blank[20]={1,9};
        for(int i=2;i<=10;i++){
            blank[i]=blank[i-1]*(9-i+2);
        }
        if(n>10)n=10;
        int ans=0;
        for(int i=0;i<=n;i++)ans+=blank[i];
        return ans;
    }
};