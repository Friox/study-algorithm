#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(string a,string b) {
    if (a.size() == b.size()) {
        return a < b;
    } else {
        return a.size() < b.size();
    }
}
int main() {
    int N;
    vector<string> wordList;
    string temp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        wordList.push_back(word);        
    }
    sort(wordList.begin(), wordList.end(), compare);
    for (int i = 0; i < N; i++){
        if (temp == wordList[i]) continue;
        cout << wordList[i];
        if (i != N - 1) cout << '\n';
        temp = wordList[i];
    }
}