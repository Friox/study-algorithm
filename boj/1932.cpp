#include <stdio.h>
int tri[500][500];
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			scanf("%d", &tri[i][j]);
		}
	}
	for (int i = n - 1; i >= 1; --i) {
		for (int j = 0; j < i; ++j) {
			tri[i - 1][j] += (tri[i][j + 1] > tri[i][j] ? tri[i][j + 1] : tri[i][j]);
		}
	}
	printf("%d",tri[0][0]);
}