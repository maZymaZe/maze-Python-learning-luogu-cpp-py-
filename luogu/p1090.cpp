#include<queue>
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	priority_queue<int> q;
	int n,t,s=0,a,b;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		q.push(-1*t);
	}
	for(int i=1;i<n;i++){
		a=q.top();
		q.pop();
		b=q.top();
		q.pop();
		q.push(a+b);
		s-=a+b;
	}
	printf("%d",s);
	return 0;
} 
