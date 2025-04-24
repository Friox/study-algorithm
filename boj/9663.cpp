#include <ios>
int n, solution, check[15];

bool isPossible(int idx) {
    // 유효한지 확인
    for (int i = 0; i < idx; ++i) {
        if (check[idx] == check[i] || (idx - i) == std::abs(check[idx] - check[i])) return false;
    }
    return true;
}

void place(int idx) {
    if (idx == n) ++solution;
    else {
        for (int i = 0; i < n; ++i) {
            check[idx] = i;
            // 유효한 수라면 다음행에도 놓음
            if (isPossible(idx)) place(idx + 1);
        }
    }
}

int main() {
    scanf("%d", &n);
    place(0);
    printf("%d", solution);
}