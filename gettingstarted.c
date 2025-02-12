#include <stdio.h>

void F(int N, char *S)
{
    for (int i = 0; i<N; i++)
        printf (S);
}

int main()
{
    int N;
    char S[11] = {0};

    scanf("%d %s", &N, S);
    F(N, S);
    return 0;
}
