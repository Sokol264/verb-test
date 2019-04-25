#include "compare.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CompareR(char* en, char* answer)
{
    if (strcmp(en, answer) == 0)
        return 1;
    else
        return 0;
}

int CompareW(char* en, char* answer)
{
    if (strcmp(en, answer) != 0)
        return 1;
    else
        return 0;
}