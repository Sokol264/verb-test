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
    float m=(p/30)*100;
    if (m<=100 && m>90){
        fprintf(rec, "5");
    }
    if (m<=90 && m>70){
        fprintf(rec, "4");
    }
    if (m<=70 && m>50){
        fprintf(rec, "3");
    }
    if (m<=50 && m>=0){
        fprintf(rec, "2");
    }
    fprintf(rec, "%d %d", p, w);
    fclose(rec);
    return 0;
}
