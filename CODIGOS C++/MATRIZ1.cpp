#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

void gerar(int matriz[][7], int &gerou);
void mostrar(int matriz[][7], int &gerou);
void maiorelemento(int matriz[][7], int &gerou);
void simetrica(int matriz[][7], int &gerou);
void diagonalp(int matriz[][7], int &gerou);


main()
{
	setlocale (LC_ALL , "Portuguese");

	int menu = 0, gerou = 0, matriz[7][7];

	do
    {
        system("cls");

        cout << "\n>>>>>>>>>> MENU DE OPÇÕES <<<<<<<<<<\n";
        cout << "         0 - Sair                  \n";
        cout << "         1 - Gerar matriz          \n";
        cout << "         2 - Mostrar matriz        \n";
        cout << "         3 - Maior elemento de cada linha\n";
        cout << "         4 - Verificar se matriz é simétrica\n";
        cout << "         5 - Elementos abaixo ou acima da diagonal principal\n";
        cin >> menu;
        fflush(stdin);

        system("cls");

        if (menu == 0)
        {
            cout << "Programa encerrado com sucesso!\n\n";

        } else if (menu == 1)
        {
            gerar(matriz, gerou);


        } else if (menu == 2)
        {
            mostrar(matriz, gerou);
            getchar();

        } else if (menu == 3 )
        {
            maiorelemento(matriz, gerou);
            getchar();

        } else if (menu == 4)
        {
            simetrica(matriz, gerou);
            getchar();

        } else if (menu == 5)
        {
            diagonalp(matriz, gerou);
            getchar();
        }



    } while (menu != 0);

}

void gerar(int matriz[][7], int &gerou)
{
    int lin, col, i, j, cont, aux;

    srand(time(NULL));

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            aux = rand() % 100;
            if(i == 0 && j == 0)
            {
                matriz[i][j] = aux;

            } else
            {
                cont = 0;
                lin = i;
                col = j;
                if(col == 0)
                {
                    col = 6;
                    lin--;

                } else
                {
                    col--;
                }
                while(cont == 0)
                {
                    if(matriz[lin][col] == aux)
                    {
                        cont = 1;
                        break;

                    } else
                    {
                        col--;
                        if(col < 0)
                        {
                            col = 6;
                            lin--;
                        }
                    }

                    if(lin < 0)
                    {
                         break;
                    }

                }

                if(cont == 0)
                {
                     matriz[i][j] = aux;

                } else
                {
                    if(j == 0)
                    {
                        j = 6;
                        i--;

                    } else
                    {
                        j--;
                    }

                }
            }
        }
    }
    cout << "Matriz gerada com sucesso!";
    getchar();
    gerou++;
}

void mostrar(int matriz[][7], int &gerou)
{
    int lin, col;
    if (gerou == 0)
    {
        cout << "Primeiro é necessário gerar a matriz! Tente novamente.";
        getchar();


    } else
    {
        cout << "Matriz formada pelos elementos:\n\n";
        for (lin = 0; lin < 7; lin++)
        {
            for (col = 0; col < 7; col++)
            {
                cout << matriz[lin][col] << "\t";
            }

            cout << endl;
        }
    }
}

void maiorelemento(int matriz[][7], int &gerou)
{
    int lin, col, maior[7], coluna[7], aux;

    if (gerou == 0)
    {
        cout << "Primeiro é necessário gerar a matriz! Tente novamente.";
        getchar();

    } else
    {
        cout << "Matriz original:\n";

         for (lin = 0; lin < 7; lin++)
        {
            for (col = 0; col < 7; col++)
            {
                cout << matriz[lin][col] << "\t";

            }

            cout << endl;
        }

        cout << "\n\nMaior elemento de cada linha:\n\n";

        for (lin = 0; lin < 7; lin++)
        {
            for (col = 0; col < 7; col++)
            {

                if (col == 0)
                {
                    maior[lin] = matriz[lin][col];
                    coluna[lin] = col;
                }
                  else if(maior[lin] < matriz[lin][col])
                {
                    maior[lin] = matriz[lin][col];
                    coluna[lin] = col;
                }
            }

            cout << maior[lin] << ", ";
        }

        for (lin = 0; lin < 7; lin++)
        {
            for (col = 0; col < 7; col++)
            {
                if (col == lin)
                {
                    aux = matriz[lin][col];
                    matriz[lin][col] = maior[lin];
                    matriz[lin][coluna[lin]] = aux;

                }

            }

        }

         cout << "\n\nMatriz com maior elemento de cada linha ocupando a diagonal principal:\n\n";

        for (lin = 0; lin < 7; lin++)
        {
            for (col = 0; col < 7; col++)
            {
                cout << matriz[lin][col] << "\t";
            }

            cout << endl;
        }
    }
}

void simetrica(int matriz[][7], int &gerou)
{
    int lin, col, cont = 0;
    if (gerou == 0)
    {
        cout << "Primeiro é necessário gerar a matriz! Tente novamente.";
        getchar();

    } else
    {
        for (lin = 0; lin < 7; lin++)
        {
            for (col = 0; col < 7; col++)
            {
                if (matriz[lin][col] != matriz[col][lin])
                {
                    cont++;
                }
            }
        }
        if (cont == 0)
        {
            cout << "Matriz é simétrica!";

        } else
        {
            cout << "Matriz não é simétrica!";
        }
    }
}

void diagonalp (int matriz[][7], int &gerou)
{
    int lin, col, acima[7][7], abaixo[7][7];

    if (gerou == 0)
    {
        cout << "Primeiro é necessário gerar a matriz! Tente novamente.";
        getchar();

    } else
    {
        cout << "Elementos acima da diagonal principal:\n\n";

        for (lin = 0; lin < 7; lin++)
        {
            for (col = 0; col < 7; col++)
            {
                if (lin < col)
                {
                    acima[lin][col] = matriz[lin][col];
                    cout << acima[lin][col] << ", ";
                }
            }
        }

        cout << "\n\nElementos abaixo da diagonal principal:\n\n";

            for (lin = 0; lin < 7; lin++)
            {
                for (col = 0; col < 7; col++)
                {
                    if (lin > col)
                    {
                        abaixo[lin][col] = matriz[lin][col];

                        cout << abaixo[lin][col] << ", ";
                    }


                }
            }
    }
}


