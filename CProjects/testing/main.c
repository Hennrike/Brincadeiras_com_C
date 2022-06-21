#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
    FILE *fp;
    int num = 2022;
    char word[10] = "coding ";
    char num2[17] = "Henrique Martins";

    struct Student{
        char name[17];
        char age[5];
        int sla;
    }aluno;

    fp = fopen("teste.txt", "wb+");
    fwrite(&aluno, sizeof(aluno), 1, fp);
    fclose(fp);

    fp = fopen("teste.txt", "rb+");
    printf("%i\n", fread(&aluno, sizeof(aluno), 1, fp));
    fclose(fp);
}
