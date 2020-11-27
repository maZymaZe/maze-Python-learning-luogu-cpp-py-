struct pr{
    int p,s;
};
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n); 
        queue<pr> q;
        q.push({0,0});
        v[0]=1;
        if(n==1)return 0;
        while(!q.empty()){
            int x=q.front().p,y=q.front().s;
            for(int i=x+nums[x];i>x;i--){
                if(i>=n-1)return y+1;
                if(!v[i]){
                    q.push({i,y+1});
                    v[i]=1;
                }else break;
            }
            q.pop();
        }
        return 0;
    }
};