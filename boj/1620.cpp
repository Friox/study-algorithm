#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);
    int N, M;
    char mStr[21];
    map<string, int> strnum;
    string numstr[100001];
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        strnum.insert(pair<string, int>(str, i));
        numstr[i] = str;
    }
    for (int i = 0; i < M; i++) {
        string mStr;
        cin >> mStr;
        if (isdigit(mStr[0])) {
            cout << numstr[stoi(mStr) - 1] << '\n';
        } else {
            string str = mStr;
            cout << strnum[str] + 1 << '\n';
        }
    }
}