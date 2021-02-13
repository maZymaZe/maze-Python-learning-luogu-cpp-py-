class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long long,vector<long long>,greater<long long>> q;
        q.push(1);
        unordered_set<long long> s;
        s.insert(1);
        int cnt=1;
        while(cnt < n){
            long long x=q.top();
            q.pop();cnt++;
            for(const int i:primes){
                long long y=x*i;
                if(!s.count(y))s.insert(y),q.push(y);
            }
        }
        return q.top();
    }
};