class Solution {
public:
    vector<int> ans;
    bool successflag=false;
    int l;
    bool dfs(string &S,int idx,long long sum,int prev){
        if(idx==l)return ans.size()>2;
        long long cur=0;
        for(int i=idx;i<l;i++){
            if(i>idx&&S[idx]=='0')break;
            cur=cur*10+S[i]-'0';
            if(cur>INT_MAX)break;
            if(ans.size()>=2){
                if(cur<sum)continue;
                else if(cur>sum)break;
            } 
            ans.push_back(cur);
            if(dfs(S,i+1,prev+cur,cur))return true;
            ans.pop_back();
        }
        return false;
       
        
    }
    vector<int> splitIntoFibonacci(string S) {
        l=S.size();
        dfs(S,0,0,0);
        return ans;
    }
};