class Solution {
public:
    int v[31][31][31][31]={0},fail[31][31][31][31]={0};
    bool mj(string&s1, string&s2,int l1,int r1,int l2,int r2){
        if(v[l1][r1][l2][r2])return !fail[l1][r1][l2][r2];
        v[l1][r1][l2][r2]=1;
        if(l1==r1)return s1[l1]==s2[l2];
        vector<int> tc(26);
        int tot=26;
        for(int i=l1,j=l2;i<=r1;i++,j++){
            if(tc[s1[i]- 'a']==0)tot--;
            else if(tc[s1[i]- 'a']==-1)tot++;
            tc[s1[i]- 'a']++;
            if(tc[s2[j]- 'a']==1)tot++;
            else if(tc[s2[j]- 'a']==0)tot--;
            tc[s2[j]- 'a']--;
            if(tot==26&&i!=r1){
                if(mj(s1,s2,l1,i,l2,j)&&mj(s1,s2,i+1,r1,j+1,r2))return true;
            }
        }
        tc.clear();tc.resize(26);
        tot=26;
        for(int i=l1,j=r2;i<=r1;i++,j--){
            if(tc[s1[i]- 'a']==0)tot--;
            else if(tc[s1[i]- 'a']==-1)tot++;
            tc[s1[i]- 'a']++;
            if(tc[s2[j]- 'a']==1)tot++;
            else if(tc[s2[j]- 'a']==0)tot--;
            tc[s2[j]- 'a']--;
            if(tot==26&&i!=r1){
                if(mj(s1,s2,l1,i,j,r2)&&mj(s1,s2,i+1,r1,l2,j-1))return true;
            }
        }
        fail[l1][r1][l2][r2]=1;
        return false;
    }
    bool isScramble(string s1, string s2) {
        vector<int> tc(26);
        int tot=26;
        for(int i=0;i<s1.size();i++){
            if(tc[s1[i]- 'a']==0)tot--;
            else if(tc[s1[i]- 'a']==-1)tot++;
            tc[s1[i]- 'a']++;
        }
        for(int i=0;i<s2.size();i++){
            if(tc[s2[i]- 'a']==0)tot--;
            else if(tc[s2[i]- 'a']==1)tot++;
            tc[s2[i]- 'a']--;
        }if(tot!=26)return false;
        return mj(s1,s2,0,s1.size()-1,0,s2.size()-1);
    }
};