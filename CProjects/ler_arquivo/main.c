#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char narquivo[50];

    printf("Nome: Henrique Martins Dutra; Matricula: 20000238; Turma: 4324\n\n");
    printf("Digite o nome do arquivo a ser lido: ");
    gets(narquivo);

    fp = fopen(narquivo, "rt");
    printf("Conteudo:\n\n");

    while(!(feof(fp))){
        printf("%c", fgetc(fp));
    }

    fclose(fp);
    return 0;
}
