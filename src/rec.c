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
    fprintf(rec, "%d %d", p, w);
    fclose(rec);
    return 0;
}
