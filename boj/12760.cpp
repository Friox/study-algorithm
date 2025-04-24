#include <algorithm>
#include <cstdio>
#include <vector>
using std::vector;

struct Player {
    int score;
    vector<int> cards;
};

int main() {
    int N, M, tmp;
    scanf("%d %d", &N, &M);
    vector<Player> players(N);
    vector<int> lastScores;
    for (Player &player : players) {
        player.cards = vector<int>(M);
        for (int i = 0; i < M; i++) scanf("%d", &player.cards[i]);
        std::sort(player.cards.begin(), player.cards.end());
    }
    for (int i = 0; i < M; i++) {
        vector<int> now;
        int idx = M - 1 - i;
        for (Player &player : players) {
            now.push_back(player.cards[idx]);
            player.cards.pop_back();
        }
        int nowMax = *std::max_element(now.begin(), now.end());
        for (Player &player : players) {
            if (player.cards[idx] == nowMax) player.score++;
        }
    }
    for (Player player : players) lastScores.push_back(player.score);
    int maxScore = *std::max_element(lastScores.begin(), lastScores.end());
    for (int i = 0; i < N; i++) {
        if (players[i].score == maxScore) printf("%d ", i + 1);
    }
}