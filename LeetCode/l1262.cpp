class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int ret=0,tot1=0,tot2=0,tot12,m11=999999,m12=999999,m21=999999,m22=999999;
        for(auto i: nums){
            if(i%3==0)ret+=i;
            if(i%3==1){
                tot1+=i;
                if(i<m11)m11=i;
                if(m11<m12)swap(m11,m12);
            }
            if(i%3==2){
                tot2+=i;
                if(i<m21)m21=i;
                if(m21<m22)swap(m21,m22);
            }
        }
        tot12=tot2+tot1;
        int tmp=99999999;
        if(tot12%3==1){
            if(m21!=999999)tmp=min(tmp,m21+m22);
            if(m12!=999999)tmp=min(tmp,m12);
            tot12=(tmp==99999999)?0:tot12-tmp;
        }
        else if(tot12%3==2){
            if(m11!=999999)tmp=min(tmp,m11+m12);
            if(m22!=999999)tmp=min(tmp,m22);
            tot12=(tmp==99999999)?0:tot12-tmp;
        }
        return ret+tot12;
    }
};