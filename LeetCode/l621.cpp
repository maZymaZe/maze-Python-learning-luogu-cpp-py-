class Solution {
public:
    int cnt[26]={0},nx[26]={0},ma=0,cma=0;
    int leastInterval(vector<char>& tasks, int n) {
        int w=tasks.size();
        for(int i=0; i<w;i++)cnt[tasks[i]-'A']++;
        for(int i=0;i<26;i++)if(cnt[i]>ma)ma=cnt[i];
        for(int i=0;i<26;i++)if(cnt[i]==ma)cma++;
        return max((cma-1)*(n+1)+cma,w);
    }
};