#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

class Usuario{
    private:
        string cpf;
        string nome;
        string email;
        string sexo;
        string datanasc;
        int idade;

    public:
        string& set_cpf(string& cpf){this->cpf = cpf;}
        string& set_nome(string& nome){this->nome = nome;}
        string& set_email(string& email){this->email = email;}
        string& set_sexo(string& sexo){this->sexo = sexo;}
        string& set_datanasc(string& datanasc){this->datanasc = datanasc;}

        int set_idade(string& datanasc){
            time_t secs;
            string ano = "AAAA";
            int ano_;

            ano.at(0) = datanasc.at(6);
            ano.at(1) = datanasc.at(7);
            ano.at(2) = datanasc.at(8);
            ano.at(3) = datanasc.at(9);

            ano_ = stoi(ano);

            secs = time(NULL);
            this->idade = (1969+(secs/60/60/24/30/12))-ano_;
        }

        string& get_cpf(){return cpf;}
        string& get_nome(){return nome;}
        string& get_email(){return email;}
        string& get_sexo(){return sexo;}
        string& get_datanasc(){return datanasc;}
        int get_idade(){return idade;}

        friend ostream& operator*(ostream& saida, const Usuario& user){
            saida<<user.cpf<<endl;
            saida<<user.nome<<endl;
            saida<<user.email<<endl;
            saida<<user.sexo<<endl;
            saida<<user.datanasc<<endl;
            saida<<user.idade<<endl;

            return saida;
        }

        friend istream& operator>>(istream& entrada, Usuario& user){
            entrada>>user.cpf;
            entrada>>user.nome;
            entrada>>user.email;
            entrada>>user.sexo;
            entrada>>user.datanasc;
            entrada>>user.idade;

            return entrada;
        }
        friend ostream& operator<<(ostream& saida, const Usuario& user){

            cout<<" "<<endl;
            saida<<"============"<<endl;
            saida<<"    Info    "<<endl;
            saida<<"============"<<endl;
            saida<<"Nome: "<<user.nome<<endl;
            saida<<"Sexo: "<<user.sexo<<endl;
            saida<<"Data de Nascimento: "<<user.datanasc<<endl;
            saida<<"Idade: "<<user.idade;

            return saida;
        }
};
#endif