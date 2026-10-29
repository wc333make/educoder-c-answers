#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mystrlen(char *s) { return *s ? 1 + mystrlen(s + 1) : 0; }
