#include "rec.h"
#include "mark.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recstat(char* login, int p, int w, int k)
{
    FILE* rec;
    char log[20];
    strcpy(log, login);
    rec = fopen(strcat(log, ".profile"), "w");
    if (rec == NULL) {
        printf("Error while creating file\n\n");
        return 1;
    }
    int m = Mark(p, k);
    fprintf(rec, "%d %d %d", m, p, w);
    fclose(rec);
    return 0;
}
