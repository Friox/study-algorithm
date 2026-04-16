#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string S, T;
    cin >> S >> T;
    while (T.length() > S.length()) {
        bool flag = T.back() == 'B';
        T.pop_back();
        if (flag) reverse(T.begin(), T.end());
    }
    cout << (S == T ? 1 : 0);
}