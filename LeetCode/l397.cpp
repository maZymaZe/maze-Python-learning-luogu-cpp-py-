class Solution {
public:
    int integerReplacement(int n) {
       
        long long ans=0;
        long long t=n;
        if(t==3)return ans+2;
        while(t!=1){
            if((t&1)==0)t>>=1,ans++;
            else if((t&3)==3){
                t=t+1;
                ans++;
            }
            else t--,ans++; 
            if(t==3)return ans+2;
        }
        return ans;
    }
};