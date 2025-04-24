#include <stdio.h>
int main() {
	long long a,b,r;
	scanf("%d %d",&a,&b);
	if (a==1) r=b*8;
	else if(a==2)r=(((b/2)*8)+((b%2)*6)+1);
	else if(a==3)r=(b*4+2);
	else if(a==4)r=(((b/2)*8)+((b%2)*2)+3);
	else r=(long long)b*8+4;
	printf("%llu",r);
}