#include <cstdio>

#include "Map.h"

void my_test() {
    Map<int, int> A, B;
    A[1] = 1;
    A[2] = 2;
    A[3] = 3;

    B[1] = 1;
    B[2] = 2;
    if (!B.Set(3, 3)) {
        B[3] = 3;
    }

    int x;
    if (A.Get(2, x)) {
        printf("found key 2 in A\n");
    }
    else {
        printf("did not find key 2 in A\n");
    }
    B[4] = 4;
    B[5] = 5;
    printf("B size: %d\n", B.Count());
    B.Delete(4);
    printf("B size: %d\n", B.Count());

    if (B.Includes(A)) {
        printf("B includes A\n");
    }
    else {
        printf("B includes A\n");
    }

    printf("A size: %d\n", A.Count());
    A.Clear();
    printf("A size: %d\n", A.Count());
}

int main() {
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto[key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto[key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    my_test();
    return 0;
}
