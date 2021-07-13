struct cmp{
    bool operator()(const vector<int>& a, const vector<int>& b){
        return a[2]<b[2];
    }
};
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<int> cp;
        int l=buildings.size();
        for(int i=0; i<l;i++){
            cp.push_back(buildings[i][0]);
            cp.push_back(buildings[i][1]);
        }
        sort(cp.begin(), cp.end());
        auto ed=unique(cp.begin(), cp.end());
        
        priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
        int p=0,pre=-1;
        vector<vector<int>> ans;
        for(auto i=cp.begin();i!=ed;++i){
            while(p<l&&*i==buildings[p][0]){
                pq.push(buildings[p]);
                p++;
            }
            while(!pq.empty()&&*i>=(pq.top())[1]){
                pq.pop();
            }
            int aa = 0;
            if(!pq.empty())aa=(pq.top())[2];
            if(aa==pre)continue;
            pre=aa;
            vector<int> rs;
            rs.push_back(*i);
            rs.push_back(aa);
            ans.push_back(move(rs));
        }
        return ans;
    }
};