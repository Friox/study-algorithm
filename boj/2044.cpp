#include <string>
#include <vector>
#include <algorithm>

struct Window {
    int width, height;
    std::string title;
};

bool compare(Window &a, Window &b) { return a.title < b.title; }

int main() {
    std::vector<Window> v;
    bool anchor[100][101] = { 0 };
    char arr[100][101], res[100][101];
    int M, N;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            res[i][j] = '.';
        }
    }
    scanf("%d %d", &M, &N);
    for (int i = 0; i < M; i++) scanf(" %s", arr[i]);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == '+' && anchor[i][j] == 0) {
                Window window = {0, 0};
                std::string title;
                bool titleFlag = false;
                int x, y;
                anchor[i][j] = 1;
                for (int k = 1; j + k < N; k++) {
                    if (titleFlag) {
                        if (arr[i][j + k] == '|') titleFlag = false;
                        else title.push_back(arr[i][j + k]);
                    } else if (arr[i][j + k] == '|') titleFlag = true;
                    if (arr[i][j + k] == '+') {
                        x = j + k;
                        anchor[i][j + k] = 1;
                        window.width = k + 1;
                        break;
                    }
                }
                for (int k = 1; i + k < M; k++) {
                    if (arr[i + k][j] == '+') {
                        y = i + k;
                        anchor[i + k][j] = 1;
                        window.height = k + 1;
                        break;
                    }
                }
                window.title = title;
                anchor[y][x] = 1;
                v.push_back(window);
            }
        }
    }

    std::sort(v.begin(), v.end(), compare);

    int o = 0;
    for (Window w: v) {
        struct { int y, x; } start = { o, o };
        res[start.y][start.x] = '+';
        res[start.y][start.x + w.width - 1] = '+';
        res[start.y + w.height - 1][start.x] = '+';
        res[start.y + w.height - 1][start.x + w.width - 1] = '+';
        for (int i = start.x + 1; i < start.x + w.width - 1; i++) {
            res[start.y][i] = '-';
            res[start.y + w.height - 1][i] = '-';
        }
        for (int i = start.y + 1; i < start.y + w.height - 1; i++) {
            res[i][start.x] = '|';
            res[i][start.x + w.width - 1] = '|';
        }
        for (int i = start.y + 1; i < start.y + w.height - 1; i++) {
            for (int j = start.x + 1; j < start.x + w.width - 1; j++) {
                res[i][j] = '.';
            }
        }
        int idx = (w.width - w.title.length()) / 2 - 1;
        res[start.y][start.x + idx] = '|';
        res[start.y][start.x + idx + w.title.length() + 1] = '|';
        for (int i = 1, j = 0; j < w.title.length(); i++, j++) res[start.y][start.x + idx + i] = w.title[j];
        o++;
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", res[i][j]);
        }
        printf("\n");
    }
    
}