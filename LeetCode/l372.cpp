class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int ans=a%1337,w=b.size(),l=b.size(),p=1;
        if(l==1&&b[0]==0)return 1;
        while(w!=1||b[l-1]!=1){
            if(b[l-1]%2)b[l-1]--,p=p*ans%1337;
            else{
                for(int i=l-w;i<l;i++){
                    if(b[i]%2)b[i]--,b[i+1]+=10;
                    b[i]/=2;
                }
                if(b[l-w]==0)w--;
                ans=ans*ans%1337;
            }
        }
        return ans*p%1337;
    }
};