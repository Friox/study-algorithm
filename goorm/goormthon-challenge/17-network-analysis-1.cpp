#include <cstdio>
#include <vector>
#include <set>
#include <stack>
using std::vector, std::set;
struct Component {
    double density;
    set<int> computers;
};

bool compare(const Component &a, const Component &b) {
    // 컴포넌트 간 조건을 판단하는 함수
    if (a.density == b.density) {
        // 밀도가 같으면,
        if (a.computers.size() == b.computers.size()) {
            // 컴퓨터 대수도 같으면 제일 작은 번호를 가진 것을 우선.
            int aComputer = *(a.computers.begin());
            int bComputer = *(b.computers.begin());
            return aComputer < bComputer;
        } else {
            // 컴퓨터의 대수가 다르면 컴퓨터의 대수가 적은것을.
            return a.computers.size() < b.computers.size();
        }
    } else {
        // 밀도가 다르면 밀도가 더 큰것을.
        return a.density > b.density;
    }
}

int main() {
    /*
    그래프탐색에 더해 탐색과 관련한 정보를 저장하여 다루어야하는 문제입니다.
    노드의 수가 많기때문에 인접 행렬로는 비효율적이니 인접리스트를 사용합니다.
    arr[X] = [Y1, Y2, Y3, ...] : X번노드가 갈수있는 노드는 Yn
    컴퓨터는 양방향 통신이 가능하다고 했으니, 인접리스트를 구성할때
    출발지 -> 도착지, 도착지 -> 출발지 두 가지 경우 모두 넣어줍니다.
    한번 DFS 또는 BFS를 수행할때 구해야하는것은 크게 두가지입니다.

    1. 통신 회선의 개수, 2. 컴퓨터 대수
    보통 DFS, BFS를 수행할때 다음노드가 연결되어있고(1) 방문가능할때(2) 스택 또는 큐에 넣습니다.
    통신 회선같은 경우는 한 출발지점에 대해 (1)번 조건을 체크할때 +1 카운트해줍니다.
    그럼 한 컴포넌트에 대해 탐색 후 누적된 카운트에 2를 나눠주면 통신 회선의 개수가 됩니다.
    연결되어있다는것은 통신회선이 존재한다는 의미고, 양방향으로 구성했으니 2를 나눠주면 됩니다.
    A - B - C가 연결되어있다고 가정해봅시다.
    1. A에서 갈 수 있는곳 탐색 (B 하나뿐, 카운트 +1)
    2. B는 방문하지 않았으니 이동.
    3. B에서 갈 수 있는곳 탐색 (A, C 두개. 카운트 +2)
    4. A는 이미 방문했으니 C로 이동합니다.
    5. C에서 갈 수 있는 곳 탐색 (B 하나뿐, 카운트 +1)
    6. 더 이상 갈수있는 곳이 없습니다. 종료 (카운트 = 4, 통신회선 2개)
    
    컴퓨터 대수는 DFS, BFS를 수행할때 동작하는 while문 또는 재귀함수의 반복횟수입니다.
    방문하지 않은, 갈수있는곳으로 간것이니 곧 컴퓨터의 대수를 의미합니다.
    저같은경우는 어차피 답으로 컴퓨터 노드번호를 출력해야하니, 대수를 저장하는 대신 Set에 담았습니다.
    Set의 원소 개수를 알면되니까요.
    또한 더 작은 번호를 가진 컴퓨터를 알아야하는데, Set 자료형은 자동으로 오름차순으로 정렬해줍니다.
    
    구한 두개를 이용하여 밀도를 구해줍니다.
    밀도와 컴퓨터Set을 하나로 묶어 배열에 넣고,
    조건에 맞는 컴포넌트를 찾아 컴퓨터 리스트를 출력하면 해결입니다.
    */
    int N, M, a, b;
    scanf("%d %d", &N, &M);
    vector<set<int>> board(N + 1); // 인접 리스트
    vector<bool> visited(N + 1); // 노드 방문여부
    vector<Component> components; // 컴포넌트를 담을 배열
    for (int i = 0; i < M; i++) {
        // 입력을 기반으로 인접 리스트 생성
        scanf("%d %d", &a, &b);
        board[a].insert(b);
        board[b].insert(a); // 양방향 추가.
    }
    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        std::stack<int> s; // 그래프 탐색을 위한 스택
        set<int> computers; // 탐색중인 컴포넌트의 컴퓨터 노드번호를 담을 Set
        s.push(i);
        int lineCnt = 0;
        while (!s.empty()) {
            int cur = s.top();
            computers.insert(cur); // 탐색중인 컴퓨터 노드번호 저장
            s.pop();
            for (auto next: board[cur]) {
                lineCnt++; // 연결체크카운트 누적 +1
                if (!visited[next]) {
                    // 연결되어있는 컴퓨터에 방문하지 않았으면 방문예정으로 표시
                    s.push(next);
                    visited[next] = true;
                }
            }
        }
        lineCnt /= 2; // 통신회선의 개수 == 연결체크카운트 / 2
        double density = lineCnt / (double)computers.size(); // 밀도 계산
        components.push_back({ density, computers }); // 컴포넌트 추가
    }
    Component result({-1, set<int>()}); // 결과 컴포넌트
    for (auto c: components) if (compare(c, result)) result = c; // 조건 탐색
    for (auto computer: result.computers) printf("%d ", computer); // 결과 출력
}