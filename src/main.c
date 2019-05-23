
#define _CRT_SECURE_NO_WARNINGS
#include "compare.h"
#include "menu.h"
#include "mark.h"
#include "read.h"
#include "rec.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main()
{
    int n = 0;
    char r;
    setlocale(LC_ALL, "Rus");
    FILE* pf;
    pf = fopen("verb.txt", "r");
    if (pf == NULL) {
        printf("error");
        return 1;
    }
    while (!feof(pf)) {
        r = getc(pf);
        if (r == '\n') {
            n++;
        }
    }
    rewind(pf);
    fclose(pf);
    main_menu(n);
    return 0;
}
