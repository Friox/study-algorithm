#include <stdio.h>
#include <string.h>
int map[20][20], buffer[20][20], n, max;
void move(int dir) {
    if (dir == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (buffer[j][i] == 0) {
                    for (int k = j + 1; k < n; ++k) {
                        if (buffer[k][i] != 0) {
                            buffer[j][i] = buffer[k][i];
                            buffer[k][i] = 0;
                            break;
                        }
                    }
                }
                for (int k = j + 1; k < n; ++k) {
                    if (buffer[k][i] == buffer[j][i]) {
                        buffer[j][i] += buffer[k][i];
                        buffer[k][i] = 0;
                        break;
                    } else if (buffer[k][i] != 0)
                        break;
                }
                if (buffer[j][i] > max) max = buffer[j][i];
            }
        }
    } else if (dir == 2) {
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (buffer[j][i] == 0) {
                    for (int k = j - 1; k >= 0; --k) {
                        if (buffer[k][i] != 0) {
                            buffer[j][i] = buffer[k][i];
                            buffer[k][i] = 0;
                            break;
                        }
                    }
                }
                for (int k = j - 1; k >= 0; --k) {
                    if (buffer[k][i] == buffer[j][i]) {
                        buffer[j][i] += buffer[k][i];
                        buffer[k][i] = 0;
                        break;
                    } else if (buffer[k][i] != 0)
                        break;
                }
                if (buffer[j][i] > max) max = buffer[j][i];
            }
        }
    } else if (dir == 3) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (buffer[i][j] == 0) {
                    for (int k = j + 1; k < n; ++k) {
                        if (buffer[i][k] != 0) {
                            buffer[i][j] = buffer[i][k];
                            buffer[i][k] = 0;
                            break;
                        }
                    }
                }
                for (int k = j + 1; k < n; ++k) {
                    if (buffer[i][k] == buffer[i][j]) {
                        buffer[i][j] += buffer[i][k];
                        buffer[i][k] = 0;
                        break;
                    } else if (buffer[i][k] != 0)
                        break;
                }
                if (buffer[i][j] > max) max = buffer[i][j];
            }
        }
    } else {
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (buffer[i][j] == 0) {
                    for (int k = j - 1; k >= 0; --k) {
                        if (buffer[i][k] != 0) {
                            buffer[i][j] = buffer[i][k];
                            buffer[i][k] = 0;
                            break;
                        }
                    }
                }
                for (int k = j - 1; k >= 0; --k) {
                    if (buffer[i][k] == buffer[i][j]) {
                        buffer[i][j] += buffer[i][k];
                        buffer[i][k] = 0;
                        break;
                    } else if (buffer[i][k] != 0)
                        break;
                }
                if (buffer[i][j] > max) max = buffer[i][j];
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            for (int k = 1; k <= 4; ++k) {
                for (int l = 1; l <= 4; ++l) {
                    for (int m = 1; m <= 4; ++m) {
                        memcpy(buffer, map, sizeof(int) * 400);
                        // printf("%d %d %d %d %d\n", i, j, k, l, m);
                        move(i);
                        move(j);
                        move(k);
                        move(l);
                        move(m);
                    }
                }
            }
        }
    }
	printf("%d", max);
}