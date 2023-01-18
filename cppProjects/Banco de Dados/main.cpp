#include <iostream>
#include <conio.h>
#include "OPTIONS.h"

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ENTER 77

using namespace std;

int main(){
    setlocale(LC_ALL, "portuguese"); //Configurando terminal para formato UTF-8

    Menu opts;
    short int ESCholder = 0;
    short int op = 1;
    char continuar;

    while(1){
        cout<<"========================"<<endl;
        cout<<"     Banco de Dados     "<<endl;
        cout<<"          HMD           "<<endl;
        cout<<"========================"<<endl;
        switch(op){
            case 1:
                cout<<"       -Cadastrar-      "<<endl;
                cout<<"        Pesquisar       "<<endl;
                cout<<"        Finalizar       "<<endl;
                break;
            case 2:
                cout<<"        Cadastrar       "<<endl;
                cout<<"       -Pesquisar-      "<<endl;
                cout<<"        Finalizar       "<<endl;
                break;
            case 3:
                cout<<"        Cadastrar       "<<endl;
                cout<<"        Pesquisar       "<<endl;
                cout<<"       -Finalizar-      "<<endl;
                break;
        }
        cout<<"Use as setas \"Cima\" e \"Baixo\" para trocar,"<<endl;
        cout<<"e a seta \"Direita\" para selecionar"<<endl;

        ESCholder = _getch();
        switch(_getch()){
            case ARROW_UP:
                op--;
                if(op<1){op = 1;}
                break;
            case ARROW_DOWN:
                op++;
                if(op>3){op = 3;}
                break;
            case ENTER:
                switch(op){
                    case 1:
                        opts.cadastro();
                        cout<<"Pressione ENTER para continuar"<<endl;
                        getch();
                        break;
                    case 2:
                        opts.pesquisar();
                        cout<<"Pressione ENTER para continuar"<<endl;
                        getch();
                        break;
                    case 3:
                        return 0;
                        break;
                }// switch selected option
        }// switch pressed key
    }// While
}// Main
