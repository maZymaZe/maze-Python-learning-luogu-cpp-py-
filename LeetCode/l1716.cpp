class Solution {
public:
    int totalMoney(int n) {
       
        int ws=n/7;
        int ans=ws*21;
        ans+=(7*ws)*(ws+1)/2;
        int rs=n%7;
        for(int i=1;i<=rs;i++){
            ans+=i;
        }
        ans+=rs*ws;
        return ans;
    }
};