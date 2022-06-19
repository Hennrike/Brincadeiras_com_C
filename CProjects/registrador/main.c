#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>

FILE *fp, *fptemp;
time_t ano;
char strtemp[15];
int flag = 0;
int op;

struct dados
{
char nome[150];
char idade[15];
short int nasc;
char cpf[15];
char fone[15];
char email[150];
char endereco[150];
}pessoa;

struct temp
{
    char nome[150];
    char idade[15];
    short int nasc;
    char cpf[15];
    char fone[15];
    char email[150];
    char endereco[150];
}pessoatemp;

void registrar()
{
    setlocale(LC_ALL, "");
    ano = time(NULL)/60/60/24/30/12+1969;

    printf("Nome: ");
    gets(pessoa.nome);
    printf("Ano de nascimento: ");
    scanf("%i", &pessoa.nasc);
    fflush(stdin);
    printf("CPF: ");
    gets(pessoa.cpf);
    printf("Numero de telefone: ");
    gets(pessoa.fone);
    printf("E-Mail: ");
    gets(pessoa.email);
    printf("Endereco: ");
    gets(pessoa.endereco);

    sprintf(strtemp, "%i", ano-pessoa.nasc);
    strcpy(pessoa.idade, strtemp);

    if (ano-pessoa.nasc == 0){
        strcpy(pessoa.idade, "recem-nascido");
    }
    else if (ano-pessoa.nasc < 0){
        strcpy(pessoa.idade, "invalidado");
    }
    
    fp = fopen("arquivo.txt", "ab+");
    fwrite(&pessoa, sizeof(struct dados), 1, fp);
    fclose(fp);
    printf("\nRegistro efetuado com sucesso...\n[Pressione qualquer tecla para continuar]");
    getchar();
}

void pesquisar()
{
    setlocale(LC_ALL, "");
    char cpftemp[150];

    fflush(stdin);
    printf("Digite o CPF do usuario: ");
    gets(cpftemp);

    fp = fopen("arquivo.txt", "rb");
    while(fread(&pessoa, sizeof(pessoa), 1, fp)==1)
    {
        if(strcmp(pessoa.cpf, cpftemp)==0)
        {
            flag++;
            printf("Exibindo registro do usuario...\n\n");
            printf("Nome: %s\n", pessoa.nome);
            printf("Idade: %s\n", pessoa.idade);
            printf("Ano de nascimento: %i\n", pessoa.nasc);
            printf("CPF: %s\n", pessoa.cpf);
            printf("Telefone: %s\n", pessoa.fone);
            printf("E-Mail: %s\n", pessoa.email);
            printf("Endereco: %s\n", pessoa.endereco);
        }
    }
    if(flag == 0){
        printf("\nNao foi possivel encontrar o usuario. Tente novamente.");
    }
    flag = 0;
    fclose(fp);
    printf("\n[Pressione qualquer tecla para continuar]");
    getchar();
}

void modificar()
{
    setlocale(LC_ALL, "");
    ano = time(NULL)/60/60/24/30/12+1969;
    char cpftemp[150];

    fflush(stdin);
    printf("Digite o CPF do usuario que deseja alterar: ");
    gets(cpftemp);

    fp = fopen("arquivo.txt", "rb+");
    fptemp = fopen("temp.txt", "ab+");
    while(fread(&pessoa, sizeof(pessoa), 1, fp)==1)
    {
        if(strcmp(pessoa.cpf, cpftemp)==0)
        {
            printf("O que deseja alterar?:\n\n[1] Nome\n[2] Ano de Nascimento\n[3] Telefone\n[4] E-Mail\n[5] Endereco\n>> ");
            scanf("%i", &op);
            fflush(stdin);

            strcpy(pessoatemp.nome, pessoa.nome);
            strcpy(pessoatemp.idade, pessoa.idade);
            pessoatemp.nasc = pessoa.nasc;
            strcpy(pessoatemp.cpf, pessoa.cpf);
            strcpy(pessoatemp.fone, pessoa.fone);
            strcpy(pessoatemp.email, pessoa.email);
            strcpy(pessoatemp.endereco, pessoa.endereco);

            switch(op){
            case 1:
                printf("Nome: ");
                gets(pessoatemp.nome);
                break;

            case 2:
                printf("Ano de nascimento: ");
                scanf("%i", &pessoatemp.nasc);
                fflush(stdin);
                sprintf(strtemp, "%i", ano-pessoatemp.nasc);
                strcpy(pessoatemp.idade, strtemp);

                if (ano-pessoatemp.nasc == 0){
                    strcpy(pessoatemp.idade, "recem-nascido");
                }
                else if (ano-pessoatemp.nasc < 0){
                    strcpy(pessoatemp.idade, "invalidado");
                }
                break;

            case 3:
                printf("Numero de telefone: ");
                gets(pessoatemp.fone);
                break;

            case 4:
                printf("E-Mail: ");
                gets(pessoatemp.email);
                break;

            case 5:
                printf("Endereco: ");
                gets(pessoatemp.endereco);
                break;
            }
            fwrite(&pessoatemp, sizeof(struct temp), 1, fptemp);
            flag++;
        }
        else{
            fwrite(&pessoa, sizeof(struct dados), 1, fptemp);
        }
    }
    if(flag == 0){
        printf("\nNao foi possivel encontrar o usuario. Tente novamente.");
    }
    else if(flag == 1){
        printf("\nUsuario alterado com sucesso.");
    }
    flag = 0;
    fclose(fptemp);
    fclose(fp);
    remove("arquivo.txt");
    rename("temp.txt", "arquivo.txt");
    printf("\n[Pressione qualquer tecla para continuar]");
    getchar();
}

void remover()
{
    char cpftemp[150];

    fflush(stdin);
    printf("Digite o CPF do usuario: ");
    gets(cpftemp);

    fp = fopen("arquivo.txt", "rb+");
    fptemp = fopen("temp.txt", "ab+");

    while(fread(&pessoa, sizeof(pessoa), 1, fp)==1)
    {
        if(strcmp(pessoa.cpf, cpftemp)==0){
            flag++;
            printf("\nUsuario encontrado. Removendo...");
        }
        else{
            fwrite(&pessoa, sizeof(struct dados), 1, fptemp);
        }
    }
    if(flag == 0){
        printf("\nNao foi possivel encontrar o usuario. Tente novamente.");
    }
    flag = 0;
    fclose(fp);
    fclose(fptemp);
    remove("arquivo.txt");
    rename("temp.txt", "arquivo.txt");
    printf("\n[Pressione qualquer tecla para continuar]");
    getchar();
}

void deletarBD(){
    printf("!CUIDADO! Esta opcao ira deletar todo o banco de dados!");
    printf("\n[1] Deletar\n[2] Voltar para o Menu\n>> ");
    scanf("%i", &op);
    fflush(stdin);

    if (op == 1){
        remove("arquivo.txt");
        printf("\nDeletado com sucesso.\n[Presisone qualquer tecla para continuar]");
        getchar();
    }
}

int menu()
{
    setlocale(LC_ALL, "");
    system("cls");
    printf("[1] Registrar pessoa\n[2] Pesquisar registro\n[3] Modificar registro\n[4] Remover registro\n[5] Deletar BD\n[6] Sair\n>> ");
    scanf("%i", &op);
    fflush(stdin);

    switch(op)
    {
    case 1:
        system("cls");
        registrar();
        break;

    case 2:
        system("cls");
        pesquisar();
        break;

    case 3:
        system("cls");
        modificar();
        break;

    case 4:
        system("cls");
        remover();
        break;

    case 5:
        system("cls");
        deletarBD();
        break;

    case 6:
        printf("\nSaindo...");
        return 0;

    default:
        break;
    }
    return 1;
}

int main()
{
    setlocale(LC_ALL, "");

    while(menu() != 0);
    return 0;
}
