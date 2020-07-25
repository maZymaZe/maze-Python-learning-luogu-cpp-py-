class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int a1,b1,a2,b2;
        int l1=a.size(),l2=b.size();
        for(int i=1;i<l1;i++){
            if(a[i]=='+'){
                a1=stoi(a.substr(0,i));
                for(int j=i;j<l1;j++){
                    if(a[j]=='i'){
                        a2=stoi(a.substr(i+1,j-i-1));
                        break;
                    }
                }
                break;
            }
        }
        for(int i=1;i<l2;i++){
            if(b[i]=='+'){
                b1=stoi(b.substr(0,i));
                for(int j=i;j<l2;j++){
                    if(b[j]=='i'){
                        b2=stoi(b.substr(i+1,j-i-1));
                        break;
                    }
                }
                break;
            }
        }
        return to_string(a1*b1-a2*b2)+"+"+to_string(a1*b2+a2*b1)+"i";
    }
};