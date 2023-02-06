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

	int matriz[5][5], l, c, menu, somac = 0, somab = 0;
	char numero[50];


	ifstream ler("numeros.txt", ios::in);

	if(ler.is_open())
    {
      for(l = 0; l < 5; l++)
      {
        for (c = 0; c < 5; c++)
        {
            ler.getline(numero, 50, ';');
            matriz[l][c] = atoi(numero);
        }
      }
        do
        {
            system("cls");
            cout << "**********MENU DE OPÇÕES**********" << endl;
            cout << "* 0 - Sair                       *" << endl;
            cout << "* 1 - Diagonal principal         *" << endl;
            cout << "* 2 - Diagonal Secundaria        *" << endl;
            cout << "* 3 - Matriz e soma dos valores  *" << endl;
            cout << "**********************************" << endl;
            cout << "Sua escolha: ";
            cin >> menu;
            fflush(stdin);

            system("cls");

            if (menu == 0)
            {
                cout << "\nPrograma encerrado com sucesso!\n";

            } else if (menu == 1)
            {
                cout << "\nValores na diagonal principal da matriz:\n\n";

                for(l = 0; l < 5; l++)
                {
                    for (c = 0; c < 5; c++)
                        {
                            if(l == c)
                            {
                                cout << matriz[l][c] << ", ";
                            }
                        }
                }

                getchar();

            } else if (menu == 2)
            {
                cout << "\nValores na diagonal secundaria da matriz:\n\n";

                for(l = 0; l < 5; l++)
                {
                    for (c = 0; c < 5; c++)
                    {
                        if(l + c == 5 - 1)
                        {
                            cout << matriz[l][c] << ", ";
                        }
                    }
                }
                  getchar();

            } else if (menu == 3)
            {
                cout << "\nMatriz formada pelos valores:\n\n";

                for(l = 0; l < 5; l++)
                {
                    for (c = 0; c < 5; c++)
                        {

                            cout << matriz[l][c] << "\t";

                            if(c > l)
                            {
                                somac += matriz[l][c];
                            }
                            if(l > c)
                            {
                                somab += matriz[l][c];
                            }
                        }

                    cout << endl;
                }

                cout << "\n\nSoma dos elementos acima da diagonal principal: " << somac;
                cout << "\nSoma dos elementos abaixo da diagonal principal: " << somab;

                getchar();

            } else
            {

                cout << "\nOpção inválida! Tente novamente!";
                getchar();
            }

        }while (menu != 0);

        ler.close();

    } else
    {
        cout << "Erro ao abrir o arquivo!";
    }

}


