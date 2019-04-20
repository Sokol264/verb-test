
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct list {
    char en1[30];
    char en2[30];
    char en3[30];
    char ru[50];
};

int main()
{
    char answer_I[20], answer_II[20], answer_III[20];
    // for (i = 0; i < 10; i++) {
    //  A[i] = i;
    //}

    setlocale(LC_ALL, "Rus");
    struct list verb[100];
    int i = 0, j = 0;
    FILE* pf;
    pf = fopen("verb.txt", "r");
    if (pf == NULL) {
        printf("error");
        return 1;
    }
    while (!feof(pf)) {
        fscanf(pf,
               "%s%s%s%s",
               verb[j].en1,
               verb[j].en2,
               verb[j].en3,
               verb[j].rus);
        j++;
    }
    fclose(pf);
    int p = 0;
    int w = 0;
    int c[10];
    for (i = 0; i < 10; i++) {
        c[i] = i;
    }
    for (i = 0; i < 10; i++) {
        int tmp, a;
        tmp = c[a = rand() % 9];
        c[a] = c[i];
        c[i] = tmp;
    }
    for (i = 0; i < 10; i++) {
        printf("%s\n", verb[c[i]].ru);
        scanf("%s %s %s", answer_I, answer_II, answer_III);
        if (strcmp(verb[c[i]].en1, answer_I) == 0)
            p++;
        else
            w++;
        if (strcmp(verb[c[i]].en2, answer_II) == 0)
            p++;
        else
            w++;
        if (strcmp(verb[c[i]].en3, answer_III) == 0)
            p++;
        else
            w++;
    }
    printf("Количество правильных ответов равно: %d\n\nКоличество "
           "неправильных "
           "ответов равно: %d\n\n",
           p,
           w);
    /*for (i = 0; i < j; i++) {
        char answer[20];
        printf("%s %10s %10s\n", verb[i].en1, verb[i].en2, verb[i].en3);
        scanf("%s", answer);
        if (!strcmp(answer, verb[i].rus)) {
            printf("Answer Right\n");
        } else
            printf("Answer Wrong\n");
    }
    system("pause");*/
>>>>>>> Add reading ability
    return 0;
}