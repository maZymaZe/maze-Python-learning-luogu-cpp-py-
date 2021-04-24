struct pr{
    int s,e;
    bool operator<(const pr& x){ return e> x.e;}
};
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pr> eg(n);
        for(int i=0;i<n;i++){
            eg[i] ={speed[i],efficiency[i]};
        }      
        sort(eg.begin(),eg.end());
        int p=0,lm=eg[0].e;
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(eg[p].s);
        long long ss=eg[0].s,MOD=1e9 + 7;
        long long ans=ss*lm;
        p++;
        while(p<n){
            while(p<n&&eg[p].e==lm){               
                if(pq.size()<k){
                    pq.push(eg[p].s);
                    ss+=eg[p].s;
                }
                else{
                    pq.push(eg[p].s);
                    ss+=eg[p].s;
                    int t=pq.top();
                    pq.pop();
                    ss-=t;
                }
                ans=max(ans,ss*lm);
                p++;
            }
            if(p>=n)break;
            lm=eg[p].e;
            if(pq.size()<k){
                pq.push(eg[p].s);
                ss+=eg[p].s;
            }
            else{
                pq.push(eg[p].s);
                ss+=eg[p].s;
                int t=pq.top();
                pq.pop();
                ss-=t;
            }
            ans=max(ans,ss*lm);
            p++;
        }
        return ans%MOD;
    }
};