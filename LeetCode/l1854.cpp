class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int mc=0,c=0,y=0,l=logs.size();
        for(int i=1950;i<=2050;i++){
            for(int j=0;j<l;j++){
                if(logs[j][0]==i)c++;
                if(logs[j][1]==i)c--;
            }
            if(c>mc)mc=c,y=i;
        }
        return y;
    }
};