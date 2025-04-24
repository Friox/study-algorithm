#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M, cnt = 0;
    vector<string> v1, v2;
    cin >> N >> M;
    v1.resize(N);
    for (int i = 0; i < N; i++) cin >> v1[i];
    sort(v1.begin(), v1.end());
    while (M--) {
        string s1;
        cin >> s1;
        if (binary_search(v1.begin(), v1.end(), s1)) {
            cnt++;
            v2.push_back(s1);
        }
    }
    sort(v2.begin(), v2.end());
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) cout << v2[i] << endl;
}