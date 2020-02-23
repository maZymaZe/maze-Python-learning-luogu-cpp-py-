#include<string>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
string ori[7],nx[7],oo,tt,t,ttt;
int m=1,head,tail;
struct pr{
	int sp;
	string ss;
}l[2300000];
int main(){
	cin>>oo>>tt;
	while(cin>>ori[m]>>nx[m]){
		m++;
		
	}
	m--;
	l[1].sp=0;
	l[1].ss=oo;
	head=tail=1;	
	if(l[head].ss==tt){
			printf("0");
	}
	else while(head<=tail){
		for(int i=1;i<=m;i++){
			//cout<<l[head].ss.size()-ori[i].size()<<endl;
			if(l[head].ss.size()>=ori[i].size())
			for(int j=0;j<=l[head].ss.size()-ori[i].size();j++){
				t=l[head].ss.substr(j,ori[i].size());
				//cout<<l[head].ss<<" "<<j<<" "<<ori[i]<<" "<<ori[i].size()<<endl;
				if(t==ori[i]){
					tail++;
					ttt=l[head].ss;
					l[tail].ss=ttt.replace(j,ori[i].size(),nx[i]);
					l[tail].sp=l[head].sp+1;
					//cout<<l[tail].ss<<"  "<<l[tail].sp<<endl;
					if(l[tail].sp==11){
						printf("NO ANSWER!");
						exit(0);
					}
					if(l[tail].ss==tt){
						printf("%d",l[tail].sp);
						exit(0);
					}
				}
			}	
		}
		head++;
	}
	return 0;
}
