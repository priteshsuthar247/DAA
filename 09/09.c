#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void lcs(char *X, char *Y, int m, int n) 
{
    int L[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++) 
    {
        for (j = 0; j <= n; j++) 
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    i = m;
    j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) 
        {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    printf("Length of LCS is %d\n", L[m][n]);
    printf("LCS of %s and %s is %s\n", X, Y, lcs);
}

void generate_random_string(char *str, int length) 
{
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length; i++) 
    {
        int key = rand() % (int)(sizeof(charset) - 1);
        str[i] = charset[key];
    }
    str[length] = '\0';
}

int main() {
    srand(time(NULL));

    int length = 6;
    char X[length + 1];
    char Y[length + 1];

    generate_random_string(X, length);
    generate_random_string(Y, length);

    printf("String 1: %s\n", X);
    printf("String 2: %s\n", Y);

    int m = strlen(X);
    int n = strlen(Y);

    lcs(X, Y, m, n);

    printf("\n");
    system("PAUSE");
    return 0;
}