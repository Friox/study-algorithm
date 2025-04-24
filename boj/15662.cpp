#include <ios>
#include <cstring>

class corg {
	// 0 : 12시, 2 : 3시, 6 : 9시
	public:
	corg(char arg[9]) {
		for (int i = 0; i < 8; i++) {
			arr[i] = (arg[i] == '1');
		}
	}

	void rotate(int a) {
		if (a == 1) {
			int temp = arr[7];
			std::memmove(arr + 1, arr, sizeof(bool) * 7);
			arr[0] = temp;
		} else {
			int temp = arr[0];
			std::memmove(arr, arr + 1, sizeof(bool) * 7);
			arr[7] = temp;
		}
	}

	bool arr[8];
};
int main() {
	int K, n, d, T;
	corg* corgs[1000];
	char args[9];
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%s", args);
		corgs[i] = new corg(args);
	}
	scanf("%d", &K);
	while (K--) {
		scanf("%d %d", &n, &d);
		int start = n - 1;
		int end = start;
		int di[2] = { 0 };
		di[(n - 1) % 2] = d;
		if (di[0] == 0) di[0] = -di[1];
		else di[1] = -di[0];
		for (int i = n - 1; i > 0; i--) {
			if (corgs[i] -> arr[6] != corgs[i - 1] -> arr[2]) start = i - 1;
			else break;
		}
		for (int i = n - 1; i < T - 1; i++) {
			if (corgs[i] -> arr[2] != corgs[i + 1] -> arr[6]) end = i + 1;
			else break;
		}
		for (int i = start; i <= end; i++) {
			corgs[i] -> rotate(di[i % 2]);
		}
	}
	int cnt = 0;
	for (int i = 0; i < T; i++) {
		cnt += corgs[i] -> arr[0];
	}
	printf("%d", cnt);
}