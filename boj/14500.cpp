#include <cstdio>
#include <vector>
using std::vector;
typedef vector<vector<bool>> shape;
int main() {
    int N, M, res = 0;
    scanf("%d %d", &N, &M);
    vector<vector<int>> arr(N, vector<int>(M));
    vector<shape> v = {
        {{ 1, 1, 1, 1 }},
        {{ 1 }, { 1 }, { 1 }, { 1 }},
        {{ 1, 1 }, { 1, 1 }},
        {{ 1, 0 }, { 1, 0 }, { 1, 1 }},
        {{ 1, 1, 1 }, { 1, 0, 0 }},
        {{ 1, 1 }, { 0, 1 }, { 0, 1 }},
        {{ 0, 0, 1 }, { 1, 1, 1 }},
        {{ 1, 1 }, { 1, 0 }, { 1, 0 }},
        {{ 1, 0, 0 }, { 1, 1, 1 }},
        {{ 0, 1 }, { 0, 1 }, { 1, 1 }},
        {{ 1, 1, 1 }, { 0, 0, 1 }},
        {{ 1, 0 }, { 1, 1 }, { 0, 1 }},
        {{ 0, 1, 1 }, { 1, 1, 0 }},
        {{ 0, 1 }, { 1, 1 }, { 1, 0 }},
        {{ 1, 1, 0 }, { 0, 1, 1 }},
        {{ 1, 1, 1 }, { 0, 1, 0 }},
        {{ 0, 1 }, { 1, 1 }, { 0, 1 }},
        {{ 0, 1, 0 }, { 1, 1, 1 }},
        {{ 1, 0 }, { 1, 1 }, { 1, 0 }}
    };
    for (int i = 0; i < N * M; i++) scanf("%d", &arr[i / M][i % M]);
    for (shape s : v) {
        int y = s.size(), x = s[0].size();
        for (int i = 0; i <= N - y; i++) {
            for (int j = 0; j <= M - x; j++) {
                int temp = 0;
                for (int k = 0; k < y; k++) {
                    for (int l = 0; l < x; l++) {
                        if (s[k][l]) temp += arr[i + k][j + l];
                    }
                }
                if (temp > res) res = temp;
            }
        }
    }
    printf("%d", res);
}