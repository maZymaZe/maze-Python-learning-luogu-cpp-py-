class Solution {
public:
    int getnum(const string&x){
        if(x[0]!=0)return stoi(x);
        if(x[1]!=0)return stoi(x.substr(1,4));
        if(x[2]!=0)return stoi(x.substr(2,4));
        return stoi(x.substr(3,4));
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<int> d;
        int l=deadends.size();
        int dp[10000]={0};
        memset(dp,0x3f,sizeof(dp));
        for(int i=0; i<l;i++){
            int dd=getnum(deadends[i]);
            d.insert(dd);
            dp[dd]=-0x3f3f3f3f;
        }
        dp[0]=0;
        const int delta[8]={1,10,100,1000,9000,9900,9990,9999},w=10000;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int h=q.front();
            q.pop();
            if(h/1000==0){
                int g=h+1000;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
                g=h+9000;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
            }else if(h/1000==9){
                int g=h-1000;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
                g=h-9000;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
            }else{
                int g=h+1000;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
                g=h-1000;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
            }

            if(h%1000/100==0){
                int g=h+100;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
                g=h+900;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
            }else if(h%1000/100==9){
                int g=h-100;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
                g=h-900;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
            }else{
                int g=h+100;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
                g=h-100;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
            }

            if(h%10==0){
                int g=h+1;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
                g=h+9;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
            }else if(h%10==9){
                int g=h-1;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
                g=h-9;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
            }else{
                int g=h+1;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
                g=h-1;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
            }

            if(h%100/10==0){
                int g=h+10;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
                g=h+90;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
            }else if(h%100/10==9){
                int g=h-10;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
                g=h-90;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
            }else{
                int g=h+10;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
                g=h-10;
                if(dp[g]==0x3f3f3f3f)dp[g]=dp[h]+1,q.push(g);
            }
        }
        int fd=getnum(target);
        if(fd==0)return 0;
        if(d.count(0))return -1;
        if(dp[fd]>0&& dp[fd]<100000)return dp[fd];
        return -1;

    }
};