class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)return "0";
        long long tn,td;
        int flag=(numerator>0)^(denominator>0);
        tn=numerator,td=denominator;
        if(tn<0)tn=-tn;
        if(td<0)td=-td;
        long long d=__gcd(tn,td);
        tn/=d,td/=d;
        if(tn%td==0)return (flag?"-":"")+to_string(tn/td);
        long long A_part=tn/td;
        long long B_part=tn%td;
        unordered_map<long long,long long> mp;
        mp.insert({B_part,0});
        int p=0,stat=0,l,r;
        vector<long long> microPart;
        while(1){
            B_part*=10;
            long long rs=B_part/td;
            microPart.push_back(rs);
            B_part%=td;
            if(B_part==0){
                stat=1;
                break;
            }
            p++;
            if(mp.count(B_part)){
                l=mp[B_part],r=p;
                break;
            }else{
                mp[B_part]=p;
            }
        
        }
        string ans;
        if(stat==1){
            ans=to_string(A_part)+'.';
            for(long long i:microPart)ans+=to_string(i);
        }else{
            ans=to_string(A_part)+'.';
            for(int i=0;i<l;i++)ans+=to_string(microPart[i]);
            ans+="(";
            for(int i=l;i<r;i++){
                ans+=to_string(microPart[i]);
            }
            ans+=")";
        }
        return (flag?"-":"")+ans;
    }
};