#include <cstdio>
#include <string>
int main() {
    int K;
    std::string str;
    scanf("%d", &K);
    while (K > 0) {
        int prd = K % 2;
        K /= 2;
        if (prd) {
            str = "4" + str;
        } else {
            K--;
            str = "7" + str;
        }
    }
    printf("%s", str.c_str());
}