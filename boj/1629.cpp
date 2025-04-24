#include <stdio.h>
typedef long long ll;
int A,B,C;
ll s(ll n){if(n==1)return A%C;ll k=s(n/2)%C;return(!(n%2)?k*k%C:k*k%C*A%C);}
int main() {scanf("%d %d %d",&A,&B,&C);printf("%lld",s(B));}