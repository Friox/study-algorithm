#include <cstdio>
unsigned char cvt(char buf[]) {
    unsigned char res = 0;
    for (int i = 7; i >= 0; i--) res += (1 << i) * (buf[7 - i] - '0');
    return res;
}
int main() {
    unsigned char mem[32], cmd, arg;
    char buf[9];
    while (scanf("%s", buf) != EOF) {
        mem[0] = cvt(buf);
        for (int i = 1; i < 32; i++) {
            scanf("%s", buf);
            mem[i] = cvt(buf);
        }
        unsigned char PC = 0, ADDR = 0;
        for (;;) {
            cmd = mem[PC] & 0xE0;
            arg = mem[PC] & 0x1F;
            PC = (PC + 1) % 32;
            if (cmd == 0x00) mem[arg] = ADDR;
            else if (cmd == 0x20) ADDR = mem[arg];
            else if (cmd == 0x40) PC = ADDR ? PC : arg;
            else if (cmd == 0x60) continue;
            else if (cmd == 0x80) ADDR--;
            else if (cmd == 0xA0) ADDR++;
            else if (cmd == 0xC0) PC = arg;
            else break;
        }
        for (int i = 7; i >= 0; i--) printf("%d", (1 << i) & ADDR ? 1 : 0);
        printf("\n");
    }
}