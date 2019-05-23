

#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include "compare.h"
#include "mark.h"
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

void main_menu(int n)
{
    char answer_I[20], answer_II[20], answer_III[20];
    int j = 0;
    int p = 0;
    int f = 0;
    int w = 0;
    FILE* pf;
    pf = fopen("verb.txt", "r");
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
    char c, ch, q, d;
    int k = 0;
    do {
        printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\tMENU\n\n\n1) Log in/Create "
               "profile\n\n\n0) Exit\n~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        scanf("%c", &c);
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
                           "do?\n\n\n1) Start test\n\n2) View stats\n\n3) "
                           "Delete profile\n\n0) "
                           "Go back\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~");
                    scanf("%c", &ch);
                    if (ch != '1' && ch != '2' && ch != '0') {
                        do {
                            scanf("%c", &ch);
                            if (ch != '1' && ch != '2' && ch != '0') {
                                printf("\nWrong input, please try again\n\n");
                            }
                        } while (ch != '1' && ch != '2' && ch != '3'
                                 && ch != '0');
                    }
                    do {
                        switch (ch) {
                        case '1':
                            printf("\nChoose difficulty "
                                   "level:\n\n1)Easy\n\n2)Normal\n\n3)"
                                   "Hard\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~");
                            scanf("%c", &d);
                            if (d != '1' && d != '2' && d != '3') {
                                do {
                                    scanf("%c", &d);
                                    if (d != '1' && d != '2' && d != '3') {
                                        printf("\nWrong input, please try "
                                               "again\n\n");
                                    }
                                } while (d != '1' && d != '2' && d != '3');
                            }
                            switch (d) {
                            case '1':
                                k = 5;
                                break;
                            case '2':
                                k = 7;
                                break;
                            case '3':
                                k = 10;
                                break;
                            }
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
                            printf("\n\nHere you will be given a "
                                   "verb in "
                                   "Russian. Translte it "
                                   "into English and write three forms the "
                                   "verb.\nComfirm input by pressing "
                                   "enter. If you want to exit input '0'\n");
                            while (!f) {
                                for (i = 0; i < k; i++) {
                                    printf("\n\n~~~~~\n\n%d out of %d\n",
                                           i + 1,
                                           k);
                                    printf("\nVerb in Russian: %s",
                                           verb[A[i]].ru);
                                    printf("\n\nInput 1st form:  ");
                                    scanf("%s", answer_I);
                                    if (answer_I[0] == '0') {
                                        f = 1;
                                        q = '1';
                                        ch = '0';
                                        break;
                                    } else {
                                        p += CompareR(verb[A[i]].en1, answer_I);
                                        w += CompareW(verb[A[i]].en1, answer_I);
                                    }

                                    printf("\n\nInput 2nd form:  ");
                                    scanf("%s", answer_II);
                                    if (answer_II[0] == '0') {
                                        f = 1;
                                        q = '1';
                                        ch = '0';
                                        break;
                                    } else {
                                        p += CompareR(
                                                verb[A[i]].en2, answer_II);
                                        w += CompareW(
                                                verb[A[i]].en2, answer_II);
                                    }
                                    printf("\n\nInput 3rd form:  ");
                                    scanf("%s", answer_III);
                                    if (answer_III[0] == '0') {
                                        f = 1;
                                        q = '1';
                                        ch = '0';
                                        break;
                                    } else {
                                        p += CompareR(
                                                verb[A[i]].en3, answer_III);
                                        w += CompareW(
                                                verb[A[i]].en3, answer_III);
                                        if (i == k - 1) {
                                            f = 1;
                                            q = '1';
                                            break;
                                        }
                                    }
                                }
                            }

                            recstat(login, p, w, k);

                            int m = Mark(p, k);

                            printf("\nYour mark is - %d\n", m);
                            printf("\nRight answers - %d\n\nWrong answers "
                                   "- "
                                   "%d\n",
                                   p,
                                   w);
                            ch = '0';
                            q = '1';
                            printf("\nTest has ended, returnig to the main "
                                   "menu");
                            f = 0;
                            break;
                        case '2':
                            readstat(login);
                            printf("\n\nPress any button when you are ready to "
                                   "continue...\n\n");
                            getchar();
                            getchar();
                            printf("Returning to menu\n");
                            ch = '0';
                            q = '1';
                            break;
                        case '3':
                            remove(strcat(login, ".profile"));
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
}
