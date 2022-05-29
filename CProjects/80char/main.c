#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char texto[80];
    int c = 0, i, j, n;

    printf("Nome: Henrique Martins Dutra; Matricula: 20000238; Turma: 4324\n\n");
    printf("Digite um texto com limite de 80 caracteres: ");
    gets(texto);

    while(texto[c] != '\0'){
        c++;
    }

    fp = fopen("string.tx_", "wt");

    // Toda a string
    for(i=0;i<c;i++){
        fputc(texto[i], fp);
    }
    fputs("\n\n", fp);

    // String invertida
    for(i--;i>=0;i--){
        fputc(texto[i], fp);
    }
    fputs("\n\n", fp);

    // Cada palavra em uma nova linha
    for(i=0;i<c;i++){
        if(texto[i] == ' '){
            fputc('\n', fp);
        }
        else{
            fputc(texto[i], fp);
        }
    }
    fputs("\n\n", fp);

    // Cada letra em uma nova linha
    for(i=0;i<c;i++){
        fprintf(fp, "%c\n", texto[i]);
    }
    fputs("\n\n", fp);

    // Quantas vezes aparece um caracter
    for(i=0;i<c;i++){
        n = 0;
        for(j=0;j<c;j++){
            if(texto[j] == texto[i]){
                n++;
            }
        }
        fprintf(fp, "%c: %i\n", texto[i], n);
    }
    
    fclose(fp);
    return 0;
}