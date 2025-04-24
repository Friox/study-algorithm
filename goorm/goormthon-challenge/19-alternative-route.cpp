#include <cstdio>
#include <queue>
#include <vector>
#include <set>
#define IMPOSSIBLE 1001
using std::vector;

int main() {
    // 익숙한 DFS로 구현했는데 18번 테스트케이스에서 시간초과나더라고요.
    // BFS로 구현했습니다.
    // 그래프를 탐색한다는 큰 틀을 벗어나지 않으면서
    // 거리를 구하는것과 다음 도시로 진행할 조건만 잘 생각하면 되는 문제였습니다.
    // 한 도시에 도착하는 방법은 여러가지로, 더 짧은 거리만 유지하면 됩니다.
    int N, M, S, E, u, v;
    scanf("%d %d %d %d", &N, &M, &S, &E);
    vector<std::set<int>> adj(N + 1); // adjacency list : 인접리스트
    vector<bool> isConstruction(N + 1); // 도시 별 공사여부를 저장할 배열
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        adj[u].insert(v); // 인접리스트 양방향 표시
        adj[v].insert(u);
    }
    for (int i = 1; i <= N; i++) {
        // 이전 루프 도시의 공사표시를 해제하고 현재 도시 공사표시.
        isConstruction[i - 1] = false;
        isConstruction[i] = true;
        // 시작지가 공사중이라면 볼가능.
        if (isConstruction[S]) { printf("-1\n"); continue; }
        vector<int> distance(N + 1, IMPOSSIBLE);
        std::queue<int> q;
        q.push(S);
        distance[S] = 1; // 출발, 거리 1로 시작
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int dest : adj[cur]) {
                // 목적지 도시가 공사중이거나, 지나온 거리가 같거나 더 먼경우 패스
                if (isConstruction[dest]) continue;
                if (distance[dest] <= distance[cur] + 1) continue;
                // 현재 경로가 더 효율적이면 거리 갱신
                distance[dest] = distance[cur] + 1;
                q.push(dest);
            }
        }
        // 가지못하면 -1, 갈 수 있으면 거리 출력
        printf("%d\n", distance[E] == IMPOSSIBLE ? -1 : distance[E]);
    }
}