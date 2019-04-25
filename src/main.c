
#define _CRT_SECURE_NO_WARNINGS
#include "rec.h"
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
    int j = 0;
    int p = 0;
    int w = 0;

    setlocale(LC_ALL, "Rus");
    FILE* pf;
    pf = fopen("verb.txt", "r");
    if (pf == NULL) {
        printf("error");
        return 1;
    }

    int A[100];
    struct list verb[100];
    while (!feof(pf)) {
        fscanf(pf,
               "%s%s%s%s",
               verb[j].en1,
               verb[j].en2,
               verb[j].en3,
               verb[j].ru);

        j++;
    }

    fclose(pf);
    int i = 0;
    char login[20];
    char c, ch;
    do {
        printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\tMENU\n\n\n1) Log in/Create "
               "profile\n\n\n0) Exit\n~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        scanf("%c", &c);
        printf("%c", c);
        if (c != '1' && c != '0') {
            do {
                scanf("%c", &c);
                if (c != '1' && c != '0') {
                    printf("Wrong input, please try again");
                }
            } while ((c != '1') && (c != '0'));
        }

        switch (c) {
        case '1':
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\nEnter username:  ");
            scanf("%s", login);
            printf("\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~\nWhat do you want to "
                   "do?\n\n\n1) Start test\n\n2) View stats\n\n0) "
                   "Go back\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~");
            scanf("%c", &ch);
            if (ch != '1' && ch != '2' && ch != '0') {
                do {
                    scanf("%c", &ch);
                    if (ch != '1' && ch != '2' && ch != '0') {
                        printf("\nWrong input, please try again\n\n");
                    }
                } while (ch != '1' && ch != '2' && ch != '0');
            }
            do {
                switch (ch) {
                case '1':

                    srand(time(NULL));
                    for (i = 0; i < 100; i++) {
                        A[i] = i;
                    }
                    for (i = 0; i < 100; i++) {
                        int tmp, a = rand() % 99 - 1;
                        tmp = A[i];
                        A[i] = A[a];
                        A[a] = tmp;
                    }
                    for (i = 0; i < 10; i++) {
                        printf("\n%s\n", verb[A[i]].ru);
                        scanf("%s %s %s", answer_I, answer_II, answer_III);
                        if (strcmp(verb[A[i]].en1, answer_I) == 0) {
                            p++;
                        } else {
                            w++;
                        }
                        if (strcmp(verb[A[i]].en2, answer_II) == 0) {
                            p++;
                        } else {
                            w++;
                        }
                        if (strcmp(verb[A[i]].en3, answer_III) == 0) {
                            p++;
                        } else {
                            w++;
                        }
                    }
                    recstat(login, p, w);
                    printf("Right answers - %d\n\nWrong answers - %d\n", p, w);
                    ch = '0';
                    c = '2';
                    printf("\nTest has ended, returnig to the main menu");
                    break;
                case '2':
                    ch = '0';
                    c = '2';
                    break;
                case '0':
                    c = '2';
                    break;
                }
            } while (ch != '0');
        case '0':
            break;
        }

    } while (c != '0');
    return 0;
}