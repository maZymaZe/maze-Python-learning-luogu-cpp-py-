#include<string>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	int k,l;
	char s[300];
	scanf("%d%s",&k,s);
	string a[10],b[10],c[10],d[10],e[10];
	a[1].assign(k+2,' ');b[1].assign(k+1,' ');b[1].append("|");c[1]=e[1]=a[1];d[1]=b[1];
	a[2].assign(" ");a[2].append(k,'-');a[2].append(" ");b[2]=b[1];c[2]=e[2]=a[2];
	d[2].assign("|");d[2].append(k+1,' ');
	a[3]=c[3]=e[3]=a[2];b[3]=d[3]=b[2];
	a[4]=e[4]=a[1];c[4]=c[2];d[4]=d[3];b[4].assign("|");b[4].append(k,' ');b[4].append("|");
	a[5]=c[5]=e[5]=a[3];b[5]=d[2];d[5]=b[2];
	a[6]=c[6]=e[6]=a[2];b[6]=b[5];d[6]=b[4];
	a[7]=a[2];c[7]=e[7]=a[1];b[7]=d[7]=b[1];
	a[8]=b[8]=c[8]=a[2];b[8]=d[8]=b[4];
	a[9]=c[9]=e[9]=a[2];b[9]=b[4];d[9]=b[2];
	a[0]=e[0]=a[2];c[0]=a[1];b[0]=d[0]=b[8];
	l=strlen(s);
	e[8]=e[9]=e[0]=a[2];
	for(int i=0;i<l;i++){
		cout<<a[(int)(s[i])-48]<<' ';
	}
	printf("\n");
	for(int j=1;j<=k;j++){
		for(int i=0;i<l;i++){
		cout<<b[(int)(s[i])-48]<<' ';
		}
		printf("\n");
	}
	for(int i=0;i<l;i++){
		cout<<c[(int)(s[i])-48]<<' ';
	}
	printf("\n");
	for(int j=1;j<=k;j++){
		for(int i=0;i<l;i++){
	cout<<d[(int)(s[i])-48]<<' ';
		}
		printf("\n");
	}
	for(int i=0;i<l;i++){
		cout<<e[(int)(s[i])-48]<<' ';
	}
	printf("\n");
	return 0;
}
