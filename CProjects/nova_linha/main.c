#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char s[30];
    int c = 0, i = 0;

    printf("Nome: Henrique Martins Dutra; Matricula: 20000238; Turma: 4324\n\n");
    printf("Digite um texto com limite de 30 caracteres: ");
    gets(s);

    while(s[c] != '\0'){
        c++;
    }
    
    fp = fopen("texto.txt", "wt");

    for(i;i<c;i++){
        fprintf(fp, "%c\n", s[i]);
    }
    
    fclose(fp);
    return 0;
}
