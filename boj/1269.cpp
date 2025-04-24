#include<stdio.h>
#include<map>
int main(){
	int a,b,n,c=0;
	std::map<int,bool>m;
	scanf("%d %d",&a,&b);
	for(int i=0;i<a;i++){scanf("%d",&n);m[n]=1;}
	for(int i=0;i<b;i++){scanf("%d",&n);if(m[n])++c;}
	printf("%d",a+b-c*2);
}