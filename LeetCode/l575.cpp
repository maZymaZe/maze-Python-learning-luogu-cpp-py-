class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(),candyType.end());
        int pre=-19260817,cnt=0,l=candyType.size();
        for(int i=0;i<l;i++){
            if(candyType[i]!=pre)pre=candyType[i],cnt++;
        }
        return (cnt*2>l)?l/2:cnt;
    }
};