// Nome: Henrique Martins Dutra
// Turma: 4324

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

FILE *fp, *fptemp;
time_t ano;
char cpftemp[15] = {0};
char strtemp[150] = {0};
int flag = 0;
int op;

struct dados
{
char nome[150];
char idade[15];
int nasc;
char cpf[15];
char fone[15];
char email[150];
char endereco[150];
}pessoa;

struct temp
{
    char nome[150];
    char idade[15];
    int nasc;
    char cpf[15];
    char fone[15];
    char email[150];
    char endereco[150];
}pessoatemp;

void validar(char *var, char msg[100]){
    while(strlen(var) == 0){
        system("cls");
        printf("Preencha o campo! Tente novamente...\n");
        printf("%s", msg);
        gets(var);
    }
}

int registrar()
{
    setlocale(LC_ALL, "");
    ano = time(NULL)/60/60/24/30/12+1969;

    printf("CPF: ");
    gets(cpftemp);
    validar(cpftemp, "CPF: ");
    fp = fopen("arquivo.txt", "rb");
    while(fread(&pessoa, sizeof(pessoa), 1, fp)==1){
        if(strcmp(pessoa.cpf, cpftemp) == 0){
            printf("Este CPF ja foi cadastrado! Tente novamente...\n");
            printf("[Pressione ENTER para retornar ao MENU]");
            getchar();
            return 0;
        }
        else if(feof(fp) != 0){
            break;
        }
    }
    strcpy(pessoa.cpf, cpftemp);
    fclose(fp);

    printf("Nome: ");
    gets(pessoa.nome);
    validar(pessoa.nome, "Nome: ");

    do{
        printf("Ano de nascimento: ");
        scanf("%i", &pessoa.nasc);
        fflush(stdin);
        if(pessoa.nasc > ano){
            system("cls");
            printf("Ano invalido, tente novamente...\n");
        }
    }while(pessoa.nasc > ano);
    sprintf(pessoa.idade, "%i", ano-pessoa.nasc);
    if (ano-pessoa.nasc == 0){
        strcpy(pessoa.idade, "recem-nascido");
    }

    printf("Numero de telefone: ");
    gets(pessoa.fone);
    validar(pessoa.fone, "Numero de telefone: ");
    printf("E-Mail: ");
    gets(pessoa.email);
    validar(pessoa.email, "E-Mail: ");
    printf("Endereco: ");
    gets(pessoa.endereco);
    validar(pessoa.endereco, "Endereco: ");

    fp = fopen("arquivo.txt", "ab+");
    fwrite(&pessoa, sizeof(pessoa), 1, fp);
    fclose(fp);
    printf("\nCadastro efetuado com sucesso...\n[Pressione ENTER para continuar]");
    getchar();
}

void pesquisar()
{
    setlocale(LC_ALL, "");

    fflush(stdin);
    printf("Digite o CPF: ");
    gets(cpftemp);
    validar(cpftemp, "Digite o CPF: ");

    fp = fopen("arquivo.txt", "rb");
    while(fread(&pessoa, sizeof(struct dados), 1, fp)==1)
    {
        if(strcmp(pessoa.cpf, cpftemp)==0)
        {
            flag++;
            printf("Exibindo cadastro...\n\n");
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
        printf("\nNao foi possivel encontrar o cadastro. Tente novamente.");
    }
    flag = 0;
    fclose(fp);
    printf("\n[Pressione ENTER para continuar]");
    getchar();
}

void modificar()
{
    setlocale(LC_ALL, "");
    ano = time(NULL)/60/60/24/30/12+1969;
    char cpftemp[150];

    fflush(stdin);
    printf("Digite o CPF do cadastro que deseja alterar: ");
    gets(cpftemp);
    validar(cpftemp, "Digite o CPF do cadastro que deseja alterar: ");

    fp = fopen("arquivo.txt", "rb+");
    fptemp = fopen("temp.txt", "ab+");
    while(fread(&pessoa, sizeof(pessoa), 1, fp)==1)
    {
        if(strcmp(pessoa.cpf, cpftemp)==0)
        {
            printf("Cadastro encontrado!\n\n");
            printf("Nome: %s\n", pessoa.nome);
            printf("Idade: %s\n", pessoa.idade);
            printf("Ano de Nascimento: %i\n", pessoa.nasc);
            printf("CPF: %s\n", pessoa.cpf);
            printf("Numero de Telefone: %s\n", pessoa.fone);
            printf("E-Mail: %s\n", pessoa.email);
            printf("Endereco: %s\n", pessoa.endereco);
            printf("\nO que deseja alterar?:\n\n[1] Nome\n[2] Ano de Nascimento\n[3] Telefone\n[4] E-Mail\n[5] Endereco\n>> ");
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
                do{
                    printf("Ano de nascimento: ");
                    scanf("%i", &pessoatemp.nasc);
                    fflush(stdin);
                    if(pessoatemp.nasc > ano){
                        system("cls");
                        printf("Ano invalido, tente novamente...\n");
                    }
                }while(pessoatemp.nasc > ano);
                sprintf(strtemp, "%i", ano-pessoatemp.nasc);
                strcpy(pessoatemp.idade, strtemp);
                if (ano-pessoatemp.nasc == 0){
                    strcpy(pessoatemp.idade, "recem-nascido");
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
            default:
                continue;
            }
            fwrite(&pessoatemp, sizeof(struct temp), 1, fptemp);
            flag++;
        }
        else{
            fwrite(&pessoa, sizeof(struct dados), 1, fptemp);
        }
    }
    if(flag == 0){
        printf("\nNao foi possivel encontrar o cadastro. Tente novamente.");
    }
    else{
        printf("\nCadastro alterado com sucesso.");
        flag = 0;
    }
    fclose(fptemp);
    fclose(fp);
    remove("arquivo.txt");
    rename("temp.txt", "arquivo.txt");
    printf("\n[Pressione ENTER para continuar]");
    getchar();
}

void remover()
{
    char cpftemp[150];

    fflush(stdin);
    printf("Digite o CPF: ");
    gets(cpftemp);
    validar(cpftemp, "Digite o CPF: ");

    fp = fopen("arquivo.txt", "rb+");
    fptemp = fopen("temp.txt", "ab+");

    while(fread(&pessoa, sizeof(pessoa), 1, fp)==1){
        if(strcmp(pessoa.cpf, cpftemp)==0){
            flag++;
            printf("\nCadastro encontrado. Removendo...");
        }
        else if(strcmp(pessoa.cpf, cpftemp)!=0){
            fwrite(&pessoa, sizeof(struct dados), 1, fptemp);
        }
    }
    if(flag == 0){
        printf("\nNao foi possivel encontrar o cadastro. Tente novamente.");
    }
    flag = 0;
    fclose(fp);
    fclose(fptemp);
    remove("arquivo.txt");
    rename("temp.txt", "arquivo.txt");
    printf("\n[Pressione ENTER para continuar]");
    getchar();
}

void deletarBD(){
    printf("!CUIDADO! Esta opcao ira deletar todo o banco de dados!");
    printf("\n[1] Deletar\n[2] Voltar para o Menu\n>> ");
    scanf("%i", &op);
    fflush(stdin);

    if (op == 1){
        fclose(fp);
        remove("arquivo.txt");
        printf("\nDeletado com sucesso.\n[Presisone qualquer tecla para continuar]");
        getchar();
    }
}

int menu()
{
    setlocale(LC_ALL, "");
    system("cls");
    printf("======================\n");
    printf("  - ATROPELANDO DB -  \n");
    printf("======================\n");
    printf("[1] Novo Cadastro\n[2] Pesquisar Cadastro\n[3] Modificar Cadastro\n[4] Remover Cadastro\n[5] Deletar BD\n[6] Sair\n>> ");
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
