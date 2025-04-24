#include <algorithm>
#include <ios>
#include <vector>

void Swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

int Partition(std::vector<int>& v, int p, int r) {
	int x = v[r];
	int i = p - 1;
	for (int j = p; j < r; j++) if (v[j] <= x) Swap(&v[++i], &v[j]);
	Swap(&v[i + 1], &v[r]);
	return i + 1;
}

int RandPartition(std::vector<int>& v, int p, int r) {
	int i = rand() % (r - p + 1) + p;
	Swap(&v[r], &v[i]);
	return Partition(v, p, r);
}

int Select(std::vector<int>& v, int p, int r, int n) {
	if (p == r) return v[p];
	int q = RandPartition(v, p, r);
	int k = q - p + 1;
	if (n == k) return v[q];
	else if (n < k) return Select(v, p, q - 1, n);
	else return Select(v, q + 1, r, n - k);
}

int kth(std::vector<int>& a, int k) {
	int ans = 0;
    std::random_shuffle(a.begin(), a.end());
	ans = Select(a, 0, a.size() - 1, k);
	return ans;
}