class Solution {
public:
    string removeKdigits(string num, int k) {
        int l=num.size();
        if(l<=k)return string("0");
        stack<char> s;
        for(int i=0;i<l;i++)
        {
            if(s.empty())s.push(num[i]);
            else{
                while(k&&(!s.empty())&&num[i]<s.top()){
                    s.pop();k--;
                }
                s.push(num[i]);
            }
        }
        while(k)s.pop(),k--;
        int cnt=0,j;
        char t1[10004]={0},t2[10004]={0};
        while(!s.empty()){t1[cnt++]=s.top(),s.pop();}
        for(j=cnt-1;j>=0;j--)if(t1[j]!='0')break;
        if(j<0)return string("0");
        if(j==0)return string(1,t1[0]);
        cnt=j;
        for(int i=j;i>=0;i--){
            t2[cnt-i]=t1[i];
        }
        return string(t2);

    }
};