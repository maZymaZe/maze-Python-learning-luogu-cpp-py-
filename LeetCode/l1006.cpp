class Solution {
public:
    int clumsy(int N) {
        const int rest[4]={0,1,1,1};
        const int spj[7]={1,1,2,6,7,7,8};
        int ans = 0;
        if(N>6){
            ans+=N*(N-1)/(N-2);
            for(int i=N-3;i>=4;i-=4){
                ans+=i-(i-1)*(i-2)/(i-3);
            }
            ans+=rest[(N-3)%4];
        }
        else ans=spj[N];
        return ans;
    }
};