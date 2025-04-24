#include <stdio.h>

const int DIRPOS[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
int A, B, N, M;
int map[100][100] = {0};

class robot {
    public:
    robot(int mX, int mY, int mD, int mID) { x = mX - 1, y = mY -1, d = mD, id = mID; }

    bool Go() {
        int nY = y + DIRPOS[d][0];
        int nX = x + DIRPOS[d][1];
        if (nY < 0 || nY >= B || nX < 0 || nX >= A) {
            // 벽 충돌
            printf("Robot %d crashes into the wall", id);
            return true;
        }
        if (map[nY][nX] != 0) {
            // 로봇 충돌
            printf("Robot %d crashes into robot %d", id, map[nY][nX]);
            return true;
        }
        map[nY][nX] = map[y][x];
        map[y][x] = 0;
        x = nX;
        y = nY;
        return false;
    }

    void TurnLeft() { d = (d + 1) % 4; }
    void TurnRight() { d = (d + 3) % 4; }

    private:
    int x, y, d, id;
};

int main() {
    int iX, iY, iD;
    char cD;
    scanf("%d %d %d %d", &A, &B, &N, &M);
    robot *robots[100];
    for (int i = 1; i <= N; i++) {
        scanf("%d %d %c", &iX, &iY, &cD);
        if (cD == 'N') iD = 0;
        else if (cD == 'W') iD = 1;
        else if (cD == 'S') iD = 2;
        else iD = 3;
        robots[i - 1] = new robot(iX, iY, iD, i);
        map[iY - 1][iX - 1] = i;
    }
    for (int i = 0; i < M; i++) {
        int iN, iC;
        char iCom;
        scanf("%d %c %d", &iN, &iCom, &iC);
        for (int j = 0; j < iC; j++) {
            if (iCom == 'L') robots[iN - 1]->TurnLeft();
            else if (iCom == 'R') robots[iN - 1]->TurnRight();
            else {
                if (robots[iN - 1]->Go()) {
					return 0;
				}
            }
        }
		for (int k = 0; k < B; k++) {
			for (int l = 0; l < A; l++) {
				printf("%d\t", map[k][l]);
			}
			printf("\n");
		}
		printf("\n");
    }
	printf("OK");
}