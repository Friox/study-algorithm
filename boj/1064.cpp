#include <algorithm>
#include <stdio.h>
#include <math.h>
double getLength(double x1, double y1, double x2, double y2) {
	double x = pow(x2 - x1, 2);
	double y = pow(y2 - y1, 2);
	return sqrt(x + y);
}
double getInclination(double x1, double y1, double x2, double y2) { return abs(y2 - y1) / abs(x2 - x1); }
int main() {
	double p[6];
	for (int i = 0; i < 6; ++i) scanf("%lf", &p[i]);
	if (getInclination(p[0], p[1], p[2], p[3]) == getInclination(p[2], p[3], p[4], p[5])) {
		printf("-1");
	} else {
		double len1 = getLength(p[0], p[1], p[2], p[3]);
		double len2 = getLength(p[2], p[3], p[4], p[5]);
		double len3 = getLength(p[0], p[1], p[4], p[5]);
		double sit1 = 2 * (len1 + len2);
		double sit2 = 2 * (len2 + len3);
		double sit3 = 2 * (len1 + len3);
		printf("%.20lf", std::max({sit1, sit2, sit3}) - std::min({sit1, sit2, sit3}));
	}
}