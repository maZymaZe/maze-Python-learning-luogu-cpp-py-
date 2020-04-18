class Solution {
public:
    string countOfAtoms(string formula) {
        string resstr="";
        map<string,int> hsmp;
        f(formula,0,hsmp);
        for(auto &item :hsmp){
            resstr+=item.first;
            if(item.second>1)resstr+=to_string(item.second);
        }
        return resstr;
    }
    int f(string &formula,int now,map<string,int>&hsmp){
        int fs=formula.size();
        if(now>=fs||formula[now]==')'){
            return now+1;
        }
        while(now<fs){
            if(formula[now]=='('){
                map<string,int> tmp;
                now=f(formula,now+1,tmp);
                int cnt=0;
                while(now<fs&&formula[now]>='0'&&formula[now]<='9'){
                    cnt=cnt*10+formula[now++]-'0';
                }
                if(cnt>1){
                    for(auto &item:tmp){
                        item.second*=cnt;
                    }
                }
                for(auto &item:tmp){
                    hsmp[item.first]+=item.second;
                }
            }
            else if (formula[now]==')'){
                return now+1;
            }
            else{
                string name=string(1,formula[now++]);
                while(now<fs&&formula[now]>='a'&&formula[now]<='z'){
                    name+=formula[now++];
                }
                int cnt=0;
                while(now<fs&&formula[now]>='0'&&formula[now]<='9'){
                    cnt=cnt*10+formula[now++]-'0';
                }
                if(cnt>0){
                    hsmp[name]+=cnt;
                }
                else{
                    hsmp[name]+=1;
                }
            }
        }
        return now;
    }
       
};