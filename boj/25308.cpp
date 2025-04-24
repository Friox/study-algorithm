#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

struct pos { double x, y; };
pos arr[8];
double iArr[8];
int cnt = 0;
double sin45 = sin(45 * M_PI / 180);
int cv(int a) { return (a > 7 ? a % 8 : a); }
pos s(int a) { return arr[cv(a)]; }

void swap(int i, int j) {
	double temp = iArr[i];
	iArr[i] = iArr[j];
	iArr[j] = temp;
}

void convertPos() {
	arr[0] = {0, iArr[0]};
	arr[2] = {iArr[2], 0};
	arr[4] = {0, -iArr[4]};
	arr[6] = {-iArr[6], 0};
	double temp;
	
	for (int i = 1; i < 8; i += 2) {
		temp = iArr[i] * sin45;
		arr[i] = {temp, temp};
		if (i == 3) arr[i].y *= -1;
		else if (i == 5) {
			arr[i].x *= -1;
			arr[i].y *= -1;
		}
		else if (i == 7) arr[i].x *= -1;
	}
}

void cycle(int depth, int n, int r) {
	if (depth == r) {
		convertPos();
		int c = 0;
		for (int i = 0; i < 8; i++) {
			/*
			bool flag = 0;
			if (s(i + 2).y > s(i).y) {
				flag = 1;
				int temp = s(i + 2).y;
				arr[cv(i + 2)].y = s(i).y;
				arr[cv(i)].y = temp;
			}
			*/
			// double a = (s(i).y * (s(i + 1).x - s(i + 2).x)) + (s(i + 1).y * (s(i + 2).x - s(i).x)) + (s(i + 2).y * (s(i).x - s(i + 1).x));
			/*
			if (flag) {
				int temp = s(i + 2).y;
				arr[cv(i + 2)].y = s(i).y;
				arr[cv(i)].y = temp;
			}
			*/
			// double a = s(i).x * s(i + 1).y + s(i + 1).x * s(i + 2).y + s(i + 2).x * s(i).y - (s(i + 1).x * s(i).y + s(i + 2).x * s(i + 1).y + s(i).x * s(i + 2).y);
			double a = (s(i + 2).x - s(i).x) * (s(i + 1).y - s(i).y) - (s(i + 2).y - s(i).y) * (s(i + 1).x - s(i).x);
			// double a = ((arr[cv(i + 2)].y - arr[cv(i)].y) * (arr[cv(i + 1)].x)) - ((arr[cv(i)].x - arr[cv(i + 2)].x) * (0 - arr[cv(i + 1)].y));
			// double a = (s(i + 2).x - s(i).x) * (s(i + 1).y - s(i).y) - (s(i + 1).x - s(i).x) * (s(i + 2).y - s(i).y);
			// double a = ((arr[cv(i + 2)].x - arr[cv(i)].x) * (arr[cv(i + 1)].y - arr[cv(i)].y) - (arr[cv(i + 2)].x - arr[cv(i)].x) * (arr[cv(i + 2)].y - arr[cv(i)].y));
			// double a = (arr[cv(i + 2)]) * (arr[cv(i + 1)] - arr[cv(i)]) - (0 - arr[cv(i)]) * (arr[cv(i + 1)]);
			// double a = ((arr[cv(i + 2)]) * (arr[cv(i + 1)] - arr[cv(i)]) - (0 - arr[cv(i)]) * (arr[cv(i + 1)]));
			// double a = (arr[cv(i)] * (arr[cv(i + 1)] - arr[cv(i + 2)])) + (arr[cv(i + 1)] * arr[cv(i + 2)]);
			// double a = arr[cv(i + 2)] * (arr[cv(i + 1)] - arr[cv(i)]) - (arr[cv(i + 1)] * -arr[cv(i)]);
			// printf("(%f %f, %f %f, %f %f) %f\n", s(i).x, s(i).y, s(i + 1).x, s(i + 1).y, s(i + 2).x, s(i + 2).y, a);
			if (a >= 0) c++;
		}
		if (c == 8) cnt++;
		return;
	}
	for (int i = depth; i < n; i++) {
		swap(i, depth);
		cycle(depth + 1, n, r);
		swap(i, depth);
	}
}

int main() {
	for (int i = 0; i < 8; i++) scanf("%lf", &iArr[i]);
	cycle(0, 8, 8);
	printf("%d", cnt);
}