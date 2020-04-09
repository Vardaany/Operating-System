// Banker's Algorithm

#include <stdio.h>
#include<stdlib.h>

int main()
{
    int n, m, i, j, k;
    m = 3;
    n = 5;
    int available[3] = { 3, 3, 2 };

    int a[5][3] = { { 0, 1, 0 },
                        { 2, 0, 0 },
                        { 3, 0, 2 },
                        { 2, 1, 1 },
                        { 0, 0, 2 } };

    int max[5][3] = { { 7, 5, 3 },
                       { 3, 2, 2 },
                      { 9, 0, 2 },
                      { 2, 2, 2 },
                      { 4, 3, 3 }};




    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - a[i][j];
    }
     int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {

                    int f = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > available[j]){
                        f = 1;
                         break;
                    }
                }

                if (f == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        available[y] += a[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    printf("This is the sequence of Safe State\n");
    for (i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
    printf(" P%d", ans[n - 1]);

    return (0);

}
