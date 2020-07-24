class Solution {
public:
    string multiply(string num1, string num2) {
        int a[120]={0},b[120]={0},c[240]={0};
        int l1=num1.size(),l2=num2.size(),l3=230;
        for(int i=l1-1;i>=0;i--)a[l1-i]=num1[i]-'0';
        for(int i=l2-1;i>=0;i--)b[l2-i]=num2[i]-'0';
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                c[i+j-1]+=a[i]*b[j];
            }
        }
        for(int i=1;i<=230;i++){
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
        while(c[l3]==0&&l3>1)l3--;
        char s3[240]={0};
        for(int i=l3;i>=1;i--)s3[l3-i]=c[i]+'0';
        s3[l3]='\0';
        return string(s3);
    }
};