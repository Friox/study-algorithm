#include <stdio.h>

int main() {
	int n, dp[1000001]={0,1,2};
	scanf("%d", &n);
	for (int i=3; i<=n; i++) dp[i]=(dp[i-2]+dp[i-1]) % 15746;
	printf("%d", dp[n]);
}