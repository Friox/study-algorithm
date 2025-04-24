#include <stdio.h>

int main() {
    int M, cnt = 0, S[20] = { 0 };
    char cmd[7] = { 0 };
    scanf("%d", &M);
    while (M--) {
        scanf("%s", cmd);
        if (cmd[1] == 'l') {
            for (int i = 0; i < 20; i++) S[i] = 1;
        } else if (cmd[0] == 'e') {
            for (int i = 0; i < 20; i++) S[i] = 0;
        } else {
            int param;
            scanf("%d", &param);
            if (cmd[0] == 'a') S[param - 1] = 1;
            else if (cmd[0] == 'r') S[param - 1] = 0;
            else if (cmd[0] == 'c') {
                if (cnt++) printf("\n");
                printf("%d", S[param - 1]);
            } else S[param - 1] = (S[param - 1] == 1 ? 0 : 1);
        }
    }
}