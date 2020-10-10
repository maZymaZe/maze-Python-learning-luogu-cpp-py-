class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        int l=stones.size(); 
        int s1=stones[l-1]-stones[0]+1-l;
        int s2=min(stones[l-1]-stones[l-2]-1,stones[1]-stones[0]-1);
        int mx=(s1-s2),mi,i=0,j=0;
        mi=mx;
        for(i=0;i<l;i++){
            while(j+1<l&&stones[j+1]-stones[i]+1<=l)++j;
            int cost=l-(j-i+1);
            if(j-i+1==l-1&&stones[j]-stones[i]+1==l-1)cost=2;
            mi=min(mi,cost);
        }
        return {mi,mx};
    }
};