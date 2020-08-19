class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int nw=1,cnt=1,ck[100005]={0};
        while(1){
            if(nw%K==0)return cnt;
            else{
                int w=nw%K;
                if(ck[w])return -1;
                else ck[w]++,nw=(w*10+1),cnt++;
            }
        }
    }
};