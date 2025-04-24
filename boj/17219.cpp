#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int N, M;
    map<string, string> passMap;
    cin >> N >> M;
    while (N--) {
        string mUrl, mPass;
        cin >> mUrl >> mPass;
        passMap[mUrl] = mPass;
    }
    while (M--) {
        string mUrl;
        cin >> mUrl;
        cout << passMap[mUrl] << endl;
    }
}