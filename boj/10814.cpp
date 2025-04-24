#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct person {
    int id, age;
    char name[101] = { 0 };
};

bool compare(const person& p1, const person& p2){
    if (p1.age == p2.age) {
        return p1.id < p2.id;
    } else {
        return p1.age < p2.age;
    }
}

int main() {
    int N;
    char mName[101] = { 0 };
    scanf("%d", &N);
    struct person *p1 = (struct person*)malloc(sizeof(struct person) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d %s", &p1[i].age, mName);
        strcpy(p1[i].name, mName);
        p1[i].id = i + 1;
    }
    sort(p1, p1 + N, compare);
    for (int i = 0; i < N; i++) {
        printf("%d %s", p1[i].age, p1[i].name);
        if (i != N - 1) printf("\n");
    }
}