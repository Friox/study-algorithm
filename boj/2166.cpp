#include <stdio.h>
#include <utility>
typedef std::pair<double, double> point;
double area(point origin, point a, point b) {
	double res = (a.first - origin.first) * (b.second - origin.second) - (a.second - origin.second) * (b.first - origin.first);
	return res / 2;
}

int main() {
	point arr[10000];
	int n;
	double res = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%lf %lf", &arr[i].first, &arr[i].second);
	for (int i = 1; i < n - 1; ++i) res += area(arr[0], arr[i], arr[i + 1]);
	if (res < 0) res *= -1;
	printf("%.1lf", res);
}