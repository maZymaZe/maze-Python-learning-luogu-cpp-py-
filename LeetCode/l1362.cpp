class Solution {
public:
    vector<int> closestDivisors(int num) {
        int a,b;
        for(int i=sqrt(num+1)+0.001;i>=1;i--){
            if((num+1)%i==0){
                a=i,b=(num+1)/i;
                break;
            }
        }
        num+=2;
        vector<int> ans;
        ans.clear();
        for(int i=sqrt(num);i>=1;i--){
            if(num%i==0){               
                if(num/i-i<b-a)a=i,b=num/i;
                break;
            }
        }
        
        
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};