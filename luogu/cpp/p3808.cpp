#include <string>
#include <vector>
#include<queue>
#include<iostream>
const int SUM_OF_PATTERN_LENGTH = 1e6 + 50;
const int LETTER_SIZE = 30;

struct Trie {
    int vis[LETTER_SIZE], fail, exist;
};
std::vector<Trie> trie(SUM_OF_PATTERN_LENGTH);
int cnt = 0;
void TrieInsert(std::vector<Trie>& trie, const std::string& s) {
    int p = 0, l = s.size();
    for (int i = 0; i < l; i++) {
        if (!trie[p].vis[s[i] - 'a']) {
            trie[p].vis[s[i] - 'a'] = ++cnt;
        }
        p = trie[p].vis[s[i] - 'a'];
    }
    trie[p].exist++;
}
void GetFail(std::vector<Trie>& trie){
    std::queue<int> q;trie[0].fail=0;
    for(int i=0;i<26;i++){
        if(trie[0].vis[i])
       { 
           trie[trie[0].vis[i]].fail=0;
           q.push(trie[0].vis[i]);
       }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            if(trie[u].vis[i]){
                trie[trie[u].vis[i]].fail=trie[trie[u].fail].vis[i];
                q.push(trie[u].vis[i]);
            }
            else trie[u].vis[i]=trie[trie[u].fail].vis[i];
        }
    }
}
int AC_Query(std::vector<Trie>& trie,const std::string& s){
    int l=s.size();
    int p=0,ans=0;
    for(int i=0;i<l;i++){
        p=trie[p].vis[s[i] - 'a'];
        for(int t=p;t&&trie[t].exist!=-1;t=trie[t].fail){
            ans+=trie[t].exist;
            trie[t].exist=-1;
        }
    }
    return ans;
}
int main(){
    int n;
    std::cin>>n;
    std::string tt;
    for(int i=1;i<=n;i++){
        std::cin >>tt;
        TrieInsert(trie,tt);
    }
    
    GetFail(trie);
    std::cin>>tt;
    std::cout<<(AC_Query(trie,tt))<<std::endl;
    return 0;
}