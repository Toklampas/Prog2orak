#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "printing.h"

void F(int N, char* S);

int main()
{
    int N;
    char S[11] = { 0 };

    scanf("%d %s", &N, S);
    F(N, S);
    return 0;
}
