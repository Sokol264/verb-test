#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct List {
    char I_form[20];
    char II_form[20];
    char III_form[20];
    char Transl[30];
};

int main()
{
    setlocale(LC_ALL, "ru");
    int i;
    struct List Verb[10] = {{"be", "was", "been", "быть"},
                            {"beat", "beat", "beaten", "бить"},
                            {"become", "became", "become", "возврaщ."},
                            {"begin", "began", "begun", "начинаиь"},
                            {"bend", "bent", "bent", "гнуть"},
                            {"bet", "bet", "bet", "держать пари"},
                            {"bite", "bit", "bitten", "кусать"},
                            {"blow", "blew", "blown", "дуть"},
                            {"break", "broke", "broken", "ломать"},
                            {"bring", "brought", "brought", "приносить"}};

    char answer_I[20], answer_II[20], answer_III[20];
    // for (i = 0; i < 10; i++) {
    //  A[i] = i;
    //}
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
        printf("%s\n", Verb[c[i]].Transl);
        scanf("%s %s %s", answer_I, answer_II, answer_III);
        if (strcmp(Verb[c[i]].I_form, answer_I) == 0)
            p++;
        else
            w++;
        if (strcmp(Verb[c[i]].II_form, answer_II) == 0)
            p++;
        else
            w++;
        if (strcmp(Verb[c[i]].III_form, answer_III) == 0)
            p++;
        else
            w++;
    }
    printf("Количество правильных ответов равно: %d\n\nКоличество "
           "неправильных "
           "ответов равно: %d\n\n",
           p,
           w);
    return 0;
}