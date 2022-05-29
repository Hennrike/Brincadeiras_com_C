#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char narquivo[100];
    char s[40];
    int c = 0, i;

    printf("Nome: Henrique Martins Dutra; Matricula: 20000238; Turma: 4324\n\n");
    printf("Digite um texto com limite de 40 caracteres: ");
    gets(s);

    printf("Digite o nome do arquivo a ser escrito: ");
    gets(narquivo);

    while(s[c] != '\0'){
        c++;
    }

    fp = fopen(narquivo, "wt");

    for(i=0;i<c;i++){
        fputc(s[i], fp);
    }
    fputs("\n\n", fp);

    for(i=0;i<c;i++){
        if(s[i]<=122&&s[i]>=97){
            fprintf(fp, "%c\t%c\n", s[i], s[i]-32);
        }
        else{
            fprintf(fp, "%c\n", s[i]);
        }
    }
    fclose(fp);
    return 0;
}