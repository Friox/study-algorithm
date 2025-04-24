#include <ios>
int main() {int n,c=0;scanf("%d",&n);for (int i=1;i<=n;i*=10) c+=n-i+1;printf("%d",c);}