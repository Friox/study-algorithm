#include <ios>
#include <iostream>
int main() {
	std::cin.tie(0); std::cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	int N, M, q, t, a, b, c, tmp;
	std::cin >> N >> M >> q;
	int **arr = new int*[N];
	for (int i = 0; i < N; ++i) {
		arr[i] = new int[M];
		for (int j = 0; j < M; ++j) {
			std::cin >> arr[i][j];
		}
	}
	for (int i = 0; i < q; ++i) {
		std::cin >> t >> a >> b;
		if (!t) {
			std::cin >> c;
			arr[a][b] = c;
		} else {
			for (int j = 0; j < M; ++j) {
				tmp = arr[b][j];
				arr[b][j] = arr[a][j];
				arr[a][j] = tmp;
			}
			/*
			tmp = arr[b];
			arr[b] = arr[a];
			arr[a] = tmp;
			*/
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::cout << arr[i][j] << (j == M - 1 ? '\n' : ' ');
		}
	}
}