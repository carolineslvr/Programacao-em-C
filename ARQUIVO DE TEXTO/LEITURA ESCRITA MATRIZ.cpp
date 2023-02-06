#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>
#include<fstream>

using namespace std;

void gerarm (int matriz[][8]);
void arquivo (int matriz[][8]);
void mostrarm();

main()
{
	setlocale (LC_ALL , "Portuguese");

	int matriz[8][8], cont = 0, menu;

	do
    {
        system("cls");
        cout << "********MENU DE OPÇÕES********" << endl;
        cout << "* 0 - Sair                   *" << endl;
        cout << "* 1 - Gerar matriz           *" << endl;
        cout << "* 2 - Escrever no arquivo    *" << endl;
        cout << "* 3 - Ler arquivo            *" << endl;
        cout << "******************************" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        system("cls");

        if (menu == 0)
        {
            cout << "\nPrograma encerrado com sucesso!\n";

        } else if (menu == 1)
        {
            cont++;
            gerarm(matriz);
            getchar();

        } else if (menu == 2)
        {
            if (cont <= 0)
            {
                cout << "\nPrimeiro é necessário gerar a matriz!";
                getchar();

            } else
            {
                arquivo(matriz);
                getchar();

            }
        } else if (menu == 3)
        {
            if (cont <= 0)
            {
                cout << "\nPrimeiro é necessário gerar a matriz!";
                getchar();

            } else
            {
                mostrarm();
                getchar();

            }

        } else
        {
            cout << "\nOpção inválida! Tente novamente.";
            getchar();
        }

    } while (menu != 0);
}

void gerarm (int matriz[][8])
{
    srand(time(NULL));

    int lin, col;

    for (lin = 0; lin < 8; lin++)
    {
        for (col = 0; col < 8; col++)
        {
            matriz[lin][col] = rand() % 100;
        }
    }

    cout << "\nMatriz gerada com sucesso!";
}

void arquivo (int matriz[][8])
{
    int lin, col;

    ofstream escrita("matriz.txt", ios::out);

    if (escrita.is_open())
    {
        for (lin = 0; lin < 8; lin++)
        {
            for (col = 0; col < 8; col++)
            {
                if (col == 0)
                {
                    escrita << matriz[lin][col];

                } else
                {
                    escrita << "," << matriz[lin][col];
                }
            }

            escrita << ",\n";
        }
        escrita.close();

        cout << "\nValores passados para o arquivo com sucesso!";

    } else
    {
        cout << "\nErro ao abrir o arquivo!";
    }
}

void mostrarm()
{
    int l, c, mat[8][8];
    char num[200];

    ifstream ler("matriz.txt");

    cout << "Dados no arquivo:\n\n";


    if (ler.is_open())
    {
        for(l = 0; l < 8; l++)
        {
            for(c = 0; c < 8; c++)
            {
                ler.getline(num, 200, ',');
                mat[l][c] = atoi(num);
                cout << mat[l][c] << "\t";
            }
            cout << "\n";
        }
        ler.close();
    } else
    {
        cout << "Erro ao abrir o arquivo!";
    }


}
