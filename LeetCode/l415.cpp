class Solution {
public:
    string addStrings(string num1, string num2) {
        int a[5200]={0},b[5200]={0},c[5200]={0},l1,l2,l3,jin=0;
        l1=num1.size(),l2=num2.size();
        for(int i=l1-1;i>=0;i--)a[l1-i-1]=num1[i]-'0';
        for(int i=l2-1;i>=0;i--)b[l2-i-1]=num2[i]-'0';
        l3=max(l1,l2)+1;
        for(int i=0;i<=l3;i++){
            c[i]=a[i]+b[i]+jin;
            jin=c[i]/10;
            c[i]%=10;
        }
        char ret[5200]={0};
        l3+=5;
        while(c[l3]==0&&l3>0)l3--;
        for(int i=0;i<=l3;i++)ret[l3-i]=c[i]+'0';
        return string(ret);
    }
};