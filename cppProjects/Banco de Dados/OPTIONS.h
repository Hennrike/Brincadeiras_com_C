#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED

#include "USER.h"

class Menu{
    public:
        static vector<Usuario> lista;

        void cadastro(){
            Usuario newUser;

            string cpf;
            string nome;
            string email;
            string sexo;
            string datanasc;
            int idade;

            ofstream ofs("Dados.txt", fstream::app);

            cout<<"======================"<<endl;
            cout<<"     Novo Usuario      "<<endl;
            cout<<"======================"<<endl;

            cout<<"CPF: ";
            cin>>cpf;
            newUser.set_cpf(cpf);
            cin.clear();

            cout<<"Nome: ";
            cin>>nome;
            newUser.set_nome(nome);
            cin.clear();

            cout<<"Email: ";
            cin>>email;
            newUser.set_email(email);
            cin.clear();

            cout<<"Sexo: ";
            cin>>sexo;
            newUser.set_sexo(sexo);
            cin.clear();

            cout<<"Data de nascimento: ";
            cin>>datanasc;
            newUser.set_datanasc(datanasc);
            cin.clear();

            newUser.set_idade(datanasc);

            ofs * newUser;

            ofs.close();
        }

        void Lista_Usuarios(){
            for(Usuario infos : lista){
                cout<<infos<<endl;
            }
        }

        void pesquisar(){
            Usuario tempUser;
            string cpf;

            ifstream ifs("Dados.txt");

            if(ifs.good()){
                while(!ifs.eof())
                {
                    ifs >> tempUser;
                    lista.push_back(tempUser);
                }
            }

            cout<<"CPF: ";
            cin>>cpf;
            cin.clear();

            auto user_iterator = find_if(
                Menu::lista.begin(),
                Menu::lista.end(),
                [=](Usuario user){return(user.get_cpf()==cpf);});

            if(user_iterator != Menu::lista.end()){
                cout<<*user_iterator<<endl;
            }
            else{
                cout<<" "<<endl;
                cout<<"Usuario nao encontrado"<<endl;
                cout<<" "<<endl;
            }
            ifs.close();
        }
};

vector<Usuario> Menu::lista;

#endif
