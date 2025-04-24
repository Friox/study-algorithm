#include <stdio.h>
typedef long long ll;
int ccw(ll a, ll b, ll c, ll d, ll e, ll f) { return (a*d+c*f+e*b)-(c*b+e*d+a*f) < 0 ? 1 : -1; }
int main() {
	int x1, y1, x2, y2;
	int x3, y3, x4, y4;
	int a, b, c, d;
	scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	a = ccw(x1, y1, x2, y2, x3, y3);
	b = ccw(x1, y1, x2, y2, x4, y4);
	c = ccw(x3, y3, x4, y4, x1, y1);
	d = ccw(x3, y3, x4, y4, x2, y2);
	printf("%d", (a * b < 0 && c * d < 0 ? 1 : 0));
}