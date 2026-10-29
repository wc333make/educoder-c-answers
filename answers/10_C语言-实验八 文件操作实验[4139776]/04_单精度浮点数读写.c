#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void save(float *a) {
    FILE *f = fopen("float.dat", "wb");
    if (!f)
        exit(1);
    fwrite(a, sizeof(float), 10, f);
    fclose(f);
}
void display(void) {
    FILE *f = fopen("float.dat", "rb");
    if (!f)
        exit(1);
    float x;
    while (fread(&x, sizeof x, 1, f) == 1) {
        uint32_t bits;
        memcpy(&bits, &x, sizeof bits);
        for (int i = 31; i >= 0; i--)
            putchar((bits >> i & 1) + '0');
        putchar('\n');
    }
    fclose(f);
}
int main(void) {
    float a[10];
    for (int i = 0; i < 10; i++)
        scanf("%f", a + i);
    save(a);
    display();
    return 0;
}
