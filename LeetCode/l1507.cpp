class Solution {
public:
    string reformatDate(string date) {
        int l= date.size(),p=0;
        while(p<l){
            if(date[p]!=' ')p++;
            else break;
        }
        string dt=date.substr(0,p-2),mn;
        const string m[13]={"","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
        for (int i=1;i<13;i++){
            if(date.substr(p+1,3)==m[i]){
                mn=to_string(i);
            }
        }
        p+=5;
        string ans=date.substr(p,4)+"-";
        if(mn.size()==1)ans+="0";
        ans+=mn+"-";
        if(dt.size()==1)ans+="0";
        ans+=dt;
        return ans;
    }
};