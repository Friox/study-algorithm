#include <stdio.h>
#include <math.h>
#include <algorithm>
int main() {
	int n;
	long long a[5000], b[3], m = 3000000001;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
	std::sort(a, a + n);
    for (int i = 0; i < n - 2; ++i) {
        int s = i + 1, e = n - 1;
        while (s < e) {
            long long sum = a[i] + a[s] + a[e];
            if (m > abs(sum)) {
                m = abs(sum);
                b[0] = a[i];
                b[1] = a[s];
				b[2] = a[e];
                if (sum == 0) break;
            }
            if (sum < 0) s++;
            else e--;
        }
    }
	for (int i = 0; i < 3; ++i) printf("%lld ", b[i]);
}