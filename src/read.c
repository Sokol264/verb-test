#include "read.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readstat(char login[])
{
    FILE* log;
    int i = 0;
    int record[2];
    log = fopen(strcat(login, ".profile"), "r");
    if (log == NULL) {
        printf("\nYou have complete no test\n\n");
        return 1;
    }
    while (!feof(log)) {
        fscanf(log, "%d", &record[i]);
        i++;
    }
    fclose(log);
    printf("\n\n\n\nIn the previous test you had:\n\nRight aswers - "
           "%d\n\nWrong aswers - %d\n\n",
           record[0],
           record[1]);
    return 0;
}