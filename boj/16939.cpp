#include <stdio.h>
#include <algorithm>
int map[24], stage[24], buffer[24];
const int MOVE_MAP[6][12][2] = {
	{{16,2},{18,3},{9,16},{8,18},{15,9},{13,8},{2,15},{3,13},{5,4},{7,5},{6,7},{4,6}},
	{{18,6},{19,7},{22,18},{23,19},{14,22},{15,23},{6,14},{7,15},{9,8},{11,9},{10,11},{8,10}},
	{{8,4},{10,6},{23,8},{21,10},{0,23},{2,21},{4,0},{6,2},{15,13},{14,15},{12,14},{13,12}},
	{{3,7},{1,5},{20,3},{22,1},{11,20},{9,22},{7,11},{5,9},{16,18},{17,16},{19,17},{18,19}},
	{{17,21},{16,20},{5,17},{4,16},{13,5},{12,4},{21,13},{20,12},{1,0},{3,1},{2,3},{0,2}},
	{{12,1},{14,0},{10,12},{11,14},{19,10},{17,11},{1,19},{0,17},{21,20},{23,21},{22,23},{20,22}},
};
int solve() {
    for (int i=0;i<6;i++) {
        std::copy(map,map+24,stage);
        for (int j=1;j<3;j++) {
            for (int k=0;k<j;k++) {
                std::copy(stage,stage+24,buffer);
                for (int l=0;l<12;l++) buffer[MOVE_MAP[i][l][0]]=stage[MOVE_MAP[i][l][1]];
                std::copy(buffer,buffer+24,stage);
            }
			bool flag=1;
			for (int k=0;k<6;k++) {
				if (!((stage[k*4]==stage[k*4+1])&&(stage[k*4+1]==stage[k*4+2])&&(stage[k*4+2]==stage[k*4+3]))) flag = 0;
			}
			if (flag) return 1;
        }
    }
	return 0;
}

#include <queue>
int main() {
	for (int i=0;i<24;i++) scanf("%d",&map[i]);
	printf("%d",solve());
	std::queue<int> mQ;
}