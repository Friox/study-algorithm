#include <stdio.h>
#include <algorithm>

struct bird {
	int interval, start, end;
};

bool birdSort(bird a, bird b) {
	if (a.interval > b.interval) return false;
	return true;
}

int main() {
	bird birds[3];
	long long result[3] = { -1, -1, -1 };
	int mA, mB, size = 0;
	for (int i = 0; i < 3; i++) scanf("%d %d %d", &birds[i].interval, &birds[i].start, &birds[i].end);
	std::sort(birds, birds + 3, birdSort);
	long long temp1 = (birds[0].interval * birds[1].interval) / std::__gcd(birds[0].interval, birds[1].interval);
	long long temp2 = (temp1 * birds[2].interval) / std::__gcd(temp1, (long long)birds[2].interval);
	for (int k = 0; k < 3; k++) {
		mA = (k > 0 ? 0 : 1);
		mB = (k == 2 ? 1 : 2);
        for (long long i = birds[k].start; i <= temp2; i += birds[k].interval) {
            long long iA = birds[mA].interval * (i / birds[mA].interval);
            long long iB = birds[mB].interval * (i / birds[mB].interval);
            bool lA = (iA + birds[mA].start <= i) && (iA + birds[mA].end >= i);
            bool lB = (iB + birds[mB].start <= i) && (iB + birds[mB].end >= i);
            if (lA && lB) {
                result[size++] = i;
                break;
            }
        }
    }
	std::sort(result, result + size);
	printf("%lld", size == 0 ? -1 : result[0]);
}