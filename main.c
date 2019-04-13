#include <stdlib.h>
#include <string.h>

struct List {
    char I_form[20];
    char II_form[20];
    char III_form[20];
    char Transl[20];
};

int main()
{
    setlocale(LC_ALL, "ru");
    int A[10], i;
    List Verb[10] = {
            "be",       "was",          "been",    "быть",         "beat",
            "beat",     "beaten",       "бить",    "become",       "became",
            "become",   "возврвщаться", "begin",   "began",        "begun",
            "начинаиь", "bend",         "bent",    "bent",         "гнуть",
            "bet",      "bet",          "bet",     "держать пари", "bite",
            "bit",      "bitten ",      "кусать",  "blow",         "blew",
            "blown",    "дуть",         "break",   "broke",        "broken",
            "ломать",   "bring",        "brought", "brought",      "приносить"};

    system("pause");
    return 0;
}