class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if(answers.empty())return 0;
        int ans=0;
        int vis[1000]= {0};
        for(auto i:answers){
            vis[i]++;
        }
        for(int i=0;i<1000;i++){
            if(vis[i]%(i+1)==0)ans+=vis[i];
            else ans+=vis[i]+(i+1)-vis[i]%(i+1);
        }
        return ans;
    }
};