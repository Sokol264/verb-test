#include "read.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readstat(char login[])
{
    FILE* log;
    int i = 0;
    int record[3];
    char lg[20];
    strcpy(lg, login);
    log = fopen(strcat(lg, ".profile"), "r");
    if (log == NULL) {
        printf("\nYou have complete no test\n\n");
        return 1;
    }
    while (!feof(log)) {
        fscanf(log, "%d", &record[i]);
        i++;
    }
    fclose(log);
    printf("\n\n\n\nIn the previous test you had:\n\nMark - "
           "%d\n\nRight aswers - "
           "%d\n\nWrong aswers - %d\n\n",
           record[0],
           record[1],
           record[2]);
    return 0;
}
