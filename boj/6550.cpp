#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    while (cin >> a >> b) {
        bool flag = false;
        int aCnt = a.length(), bCnt = b.length();
        int idx = 0;
        for (int i = 0; i < bCnt; i++) {
            if (b[i] == a[idx]) {
                if (++idx == aCnt) {
                    flag = true;
                }
            }
        }
        cout << (flag ? "Yes" : "No") << '\n';
    }    
}