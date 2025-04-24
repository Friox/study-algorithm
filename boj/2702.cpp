#include <stdio.h>

int main() {
    int T, n, m, nm;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        nm = n * m;
        while(m != 0) { 	
            int r = n % m;
            n = m;
            m = r;
        }
        printf("%d %d", nm / n, n);
        if (T != 0) printf("\n");
    }
}