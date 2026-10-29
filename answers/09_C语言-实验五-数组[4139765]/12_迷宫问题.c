#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, *maze, *path, count;
void dfs(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m || !maze[r * m + c] || path[r * m + c])
        return;
    path[r * m + c] = 1;
    if (r == n - 1 && c == m - 1) {
        printf("%d\n", ++count);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                printf("%s%d", j ? " " : "", path[i * m + j]);
            putchar('\n');
        }
    } else {
        dfs(r + 1, c);
        dfs(r, c + 1);
        dfs(r - 1, c);
        dfs(r, c - 1);
    }
    path[r * m + c] = 0;
}
int main(void) {
    scanf("%d%d", &n, &m);
    maze = malloc(n * m * sizeof(int));
    path = calloc(n * m, sizeof(int));
    for (int i = 0; i < n * m; i++)
        scanf("%d", maze + i);
    dfs(0, 0);
    free(maze);
    free(path);
    return 0;
}
