class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        int lb=big.size(),ls=small.size();
        if(lb<ls)return vector<int>();
        unordered_map<int,int> mp;
        int cnt=0,ansl=0,ansr=lb-1,tmpl=0,tmpr=0;
        for(int i=0;i<ls;i++)mp.insert({small[i],0});
        while(cnt<ls&&tmpr<lb){
            if(mp.count(big[tmpr])){
                if(mp[big[tmpr]]==0)cnt++;
                mp[big[tmpr]]++;
            }
            tmpr++;
        }
        if(cnt!=ls)return vector<int>();
        while(tmpr<=lb){ 
            while(cnt==ls){
                if(mp.count(big[tmpl])){
                    if(mp[big[tmpl]]==1)cnt--;
                    mp[big[tmpl]]--;
                }
                tmpl++;
            }
            if(ansr-ansl>tmpr-tmpl)ansl=tmpl-1,ansr=tmpr-1;
            if(tmpr==lb)break;
            while(cnt<ls&&tmpr<lb){
                if(mp.count(big[tmpr])){
                    if(!mp[big[tmpr]])cnt++;
                    mp[big[tmpr]]++;
                }
                tmpr++;
            }
        }
        return vector<int>{ansl,ansr};
    }
};