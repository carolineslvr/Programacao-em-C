#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>
#include<fstream>

using namespace std;

main()
{
	setlocale (LC_ALL , "Portuguese");

	char nome[200];
	int menu;


	do
    {
        system("cls");
        cout << "****MENU DE OPÇÕES****" << endl;
        cout << "* 0 - Sair           *" << endl;
        cout << "* 1 - Cadastrar      *" << endl;
        cout << "* 2 - Mostrar        *" << endl;
        cout << "* 3 - Consultar      *" << endl;
        cout << "**********************" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        system("cls");

        if (menu == 0)
        {
            cout << "\n\nPrograma encerrado com sucesso!\n";

        } else if (menu == 1)
        {
            cout << "Informe o seu nome: ";
            gets(nome);
            ofstream escrita("cadastro.txt", ios::app);

            if(escrita.is_open())
            {
                escrita << nome << endl;

            } else
            {
                cout << "Erro ao abrir o arquivo!";
                getchar();
            }
          escrita.close();

        } else if (menu == 2)
        {
            ifstream ler("cadastro.txt", ios::in);

            if (ler.is_open())
            {
                cout << "Dados no arquivo:\n";

                 while(!ler.eof())
                {
                    ler.getline(nome, 100);
                    cout << nome << endl;
                }
            getchar();
            } else
            {
                cout << "Erro ao abrir o arquivo!";
                getchar();
            }
        ler.close();

        } else if (menu == 3)
        {

            ifstream ler("cadastro.txt", ios::in);
            string busca;
            int cont = 0;

            if(ler.is_open())
            {
                cout << "Digite um nome para busca: ";
                getline(cin, busca);

                while (!ler.eof())
                {
                    ler.getline(nome, 200);

                    if(busca == nome)
                    {
                       cont++;
                       break;

                    } else
                    {
                         cont = 0;
                    }
                }

                if (cont != 0)
                {
                    cout << "Nome " << busca << " encontrado no documento.";
                    getchar();


                } else
                {
                    cout << "Nome " << busca << " não encontrado no doumento.";
                    getchar();
                }
            }
        ler.close();
        } else
        {
            cout << "\nOpção inválida!";
        }
    } while (menu != 0);
}
