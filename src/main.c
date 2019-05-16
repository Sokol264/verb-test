
#define _CRT_SECURE_NO_WARNINGS
#include "compare.h"
#include "read.h"
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
    int A[n];
    struct list verb[n];
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
    char c, ch, q;

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
            while (1) {
                q = '1';
                switch (q) {
                case '1':
                    printf("\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~\nWhat do you want "
                           "to "
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
                            p = 0, w = 0;
                            srand(time(NULL));
                            for (i = 0; i < n; i++) {
                                A[i] = i;
                            }
                            for (i = 0; i < n; i++) {
                                int tmp, a = rand() % n - 1;

                                tmp = A[i];
                                A[i] = A[a];
                                A[a] = tmp;
                            }
                            printf("\n\nHere you will be given given a verb in "
                                   "Russian. Translte it "
                                   "into English and write three forms the "
                                   "verb.\nComfirm input by pressing "
                                   "enter.\n\n");
                            for (i = 0; i < 10; i++) {
                                printf("%d out of 10", i + 1);
                                printf("\nVerb in Russian: %s", verb[A[i]].ru);
                                printf("\nInput 1st form:  ");
                                scanf("%s", answer_I);
                                printf("\nInput 2nd form:  ");
                                scanf("%s", answer_II);
                                printf("\nInput 3rd form:  ");
                                scanf("%s", answer_III);
                                p += CompareR(verb[A[i]].en1, answer_I);
                                w += CompareW(verb[A[i]].en1, answer_I);
                                p += CompareR(verb[A[i]].en2, answer_II);
                                w += CompareW(verb[A[i]].en2, answer_II);
                                p += CompareR(verb[A[i]].en3, answer_III);
                                w += CompareW(verb[A[i]].en3, answer_III);
                            }
                            recstat(login, p, w);
                            if (p <= 30 && p > 26) {
                                printf("\nYour mark - 5 \n");
                            }
                            if (p <= 26 && p > 21) {
                                printf("\nYour mark - 4 \n");
                            }
                            if (p <= 21 && p > 14) {
                                printf("\nYour mark - 3 \n");
                            }
                            if (p <= 14 && p >= 0) {
                                printf("\nYour mark - 2 \n");
                            }
                            printf("\nRight answers - %d\n\nWrong answers - "
                                   "%d\n",
                                   p,
                                   w);
                            ch = '0';
                            q = '1';
                            printf("\nTest has ended, returnig to the main "
                                   "menu");
                            break;
                        case '2':
                            readstat(login);
                            printf("Returning to main menu\n");
                            ch = '0';
                            q = '1';
                            break;
                        case '0':
                            ch = '0';
                            q = '0';
                            break;
                        }
                    } while (ch != '0');
                case '0':
                    break;
                }
                if (q == '0') {
                    break;
                }
            }
        case '0':
            break;
        }

    } while (c != '0');
    return 0;
}
