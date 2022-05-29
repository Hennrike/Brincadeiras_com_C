#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char s[100];
    int c = 0, i = 0;

    printf("Nome: Henrique Martins Dutra; Matricula: 20000238; Turma: 4324\n\n");
    printf("Digite um texto: ");
    gets(s);

    while(s[c] != '\0'){
        c++;
    }

    fp = fopen("texto.txt", "wt");

    for(i;i<c;i++){
        if(s[i]<=122&&s[i]>=97){
            fputc(s[i]-32, fp);
        }
        else{
            fputc(s[i], fp);
        }
    }

    fclose(fp);
    return 0;
}