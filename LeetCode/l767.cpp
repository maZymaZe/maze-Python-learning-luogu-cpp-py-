struct pr{
    char x;
    int c;
    bool operator <(const pr&t){
        return c>t.c;
    }
};
class Solution {
public:
    pr cnt[26]= {0};int v[26]={0};
    string reorganizeString(string S) {
        int l= S.size();
        for(int i=0; i<26;i++)cnt[i].x=i+'a';
        for(int i=0; i<l;i++)cnt[S[i]-'a'].c++;
        sort(cnt,cnt+26);
        if(cnt[0].c*2>l+1)return string("");
        int p=0,q=1,ccnt=0;
        string ans(l,' ');
        for(int i=0;i<l;i+=2){
            ans[i]=cnt[p].x;
            cnt[p].c--;
            if(!cnt[p].c)p++;
        }
        for(int i=1;i<l;i+=2){
            ans[i]=cnt[p].x;
            cnt[p].c--;
            if(!cnt[p].c)p++;
        }
        return ans;
    }
};