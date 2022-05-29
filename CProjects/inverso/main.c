#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char texto[100];
    int c = 0;

    printf("Nome: Henrique Martins Dutra; Matricula: 20000238; Turma: 4324\n\n");
    printf("Digite algo: ");
    gets(texto);

    while(texto[c] != '\0'){
        c++;
    }

    fp = fopen("texto.txt", "wt");

    for(c-=1;c>=0;c--){
        fputc(texto[c], fp);
    }
    
    fclose(fp);
    return 0;
}
