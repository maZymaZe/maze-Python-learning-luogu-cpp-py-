class Solution {
public:
    int consecutiveNumbersSum(int N) {
        N*=2;
        int l=sqrt(N),ans=0;
        for(int i=2;i<=l;i++){
            if(N%i==0){
                int w=N/i;
                w+=1;
                if(w-i<2)continue;
                w-=i;
                if(w%2==0)ans++;
            }
        }
        return ans+1;
    }
};