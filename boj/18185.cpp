#include <ios>
int n, buy[100001], cost, tmp;
void updateCost(int i, int weight, int value) {
    cost += weight * value;
    for (int j = 0; j < weight / 2; ++j) buy[i + j] -= value;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &buy[i]);
    for (int i = 1; i <= n; ++i) {
        if (buy[i + 1] > buy[i + 2]) {
            tmp = std::min(buy[i], buy[i + 1] - buy[i + 2]);
            updateCost(i, 5, tmp);
            tmp = std::min(buy[i], std::min(buy[i + 1], buy[i + 2]));
            updateCost(i, 7, tmp);
        } else {
            tmp = std::min(buy[i], std::min(buy[i + 1], buy[i + 2]));
            updateCost(i, 7, tmp);
            tmp = std::min(buy[i], buy[i + 1]);
            updateCost(i, 5, tmp);
        }
        cost += 3 * buy[i];
    }
    printf("%d", cost);
}