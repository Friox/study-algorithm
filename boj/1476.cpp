#include <stdio.h>

int main() {
	int y = 0, e, s, m, te = 0, ts = 0, tm = 0;
	scanf("%d %d %d", &e, &s, &m);
	while (true) {
		y++;
		if (++te > 15) te = 1;
		if (++ts > 28) ts = 1;
		if (++tm > 19) tm = 1;
		if (e == te && s == ts && m == tm) {
			printf("%d", y);
			break;
		}
	}
}