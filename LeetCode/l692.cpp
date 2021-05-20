class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> cnt;
        for(auto& word : words)cnt[word] ++;
        auto cmp=[](const pair<string,int>&a,const pair<string,int>&b){
            return a.second==b.second?a.first<b.first:a.second>b.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> q(cmp);
        for(auto&it:cnt){
            q.push(it);
            if(q.size()>k)q.pop();
        }
        vector<string> ans(k);
        for(int i=k-1;i>=0;i--){
            ans[i] =(q.top().first);
            q.pop();
        }
        return ans;
    }
};