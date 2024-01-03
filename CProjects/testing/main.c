#include <stdio.h>

int main()
{
    FILE *fp;
    int num = 2022;
    char word[4] = "2004";
    char num2[17] = "Henrique Martins";

    struct Student{
        char name[17];
        char age[5];
        int sla;
    }aluno;

    char *ptr;
    strtol(word, &ptr, 10);
    printf("%i", word);
}
