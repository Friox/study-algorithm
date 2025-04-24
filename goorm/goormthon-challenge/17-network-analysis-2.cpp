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
    if (a.density == b.density) {
        if (a.computers.size() == b.computers.size()) {
            int aComputer = *(a.computers.begin());
            int bComputer = *(b.computers.begin());
            return aComputer < bComputer;
        } else {
            return a.computers.size() < b.computers.size();
        }
    } else {
        return a.density > b.density;
    }
}

int main() {
    int N, M, a, b;
    scanf("%d %d", &N, &M);
    vector<set<int>> board(N + 1);
    vector<bool> visited(N + 1);
    vector<Component> components;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        board[a].insert(b);
        board[b].insert(a);
    }
    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        std::stack<int> s;
        set<int> computers;
        s.push(i);
        int lineCnt = 0;
        while (!s.empty()) {
            int cur = s.top();
            computers.insert(cur);
            s.pop();
            for (auto next: board[cur]) {
                lineCnt++;
                if (!visited[next]) {
                    s.push(next);
                    visited[next] = true;
                }
            }
        }
        lineCnt /= 2;
        double density = lineCnt / (double)computers.size();
        components.push_back({ density, computers });
    }
    Component result({-1, set<int>()});
    for (auto c: components) if (compare(c, result)) result = c;
    for (auto computer: result.computers) printf("%d ", computer);
}