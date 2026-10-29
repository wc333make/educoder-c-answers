#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char line[1000], command[100], arg[300], file[300];
    if (!fgets(line, sizeof line, stdin))
        return 1;
    if (sscanf(line, "%99s%299s%299s", command, arg, file) < 2 || strcmp(command, "type_c")) {
        printf("指令错误");
        return 0;
    }
    int paged = !strcmp(arg, "/p");
    const char *name = paged ? file : arg;
    char path[600];
    snprintf(path, sizeof path, "src/step1_1/%s", name);
    FILE *f = fopen(path, "r");
    if (!f)
        return 1;
    int row = 0;
    char buffer[4096];
    while (fgets(buffer, sizeof buffer, f)) {
        if (paged && row && row % 10 == 0) {
            int c;
            do {
                c = getchar();
            } while (c != EOF && c != 'q');
            if (c == EOF)
                break;
        }
        printf("%d  %s", paged ? row % 10 + 1 : row + 1, buffer);
        row++;
    }
    fclose(f);
    return 0;
}
