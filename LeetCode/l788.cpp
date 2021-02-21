class Solution {
public:
    int rotatedDigits(int N) {
        int ans=0,f=0;
        for(int i=1;i<=N;i++){
            int t=i,f=0;
            while(t){
                int p=t% 10;
                t/=10;
                if(p==0||p==1||p==8);
                else if(p==2||p==5||p==6||p==9)f=1;
                else{f=0;break;}
            }
            ans+=f;
        }
        return ans;
    }
};