#include "rec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recstat(char* login, int p, int w)
{
    FILE* rec;
    rec = fopen(strcat(login, ".profile"), "w");
    if (rec == NULL) {
        printf("Error while creating file\n\n");
        return 1;
    }
    if (p <= 30 && p > 26) {
        fprintf(rec, "5 ");
    }
    if (p <= 26 && p > 21) {
        fprintf(rec, "4 ");
    }
    if (p <= 21 && p > 14) {
        fprintf(rec, "3 ");
    }
    if (p <= 14 && p >= 0) {
        fprintf(rec, "2 ");
    }
    fprintf(rec, "%d %d", p, w);
    fclose(rec);
    return 0;
}
