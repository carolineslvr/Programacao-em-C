#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

void mostrar (int (*mat)[5], int **px);
void somar (int (*matriz)[5], int *px);
void inverter (int (*matriz)[5], int *px);

main()
{
	setlocale (LC_ALL , "Portuguese");
	srand(time(NULL));

	int *pc = new int(0);
	int *pmenu =  new int;
	int *x = new int;
	int (*matriz)[5];
	int *a = new int;
    int *b = new int;



	do
    {
        system ("cls");

        cout << "********** MENU DE OPÇÕES *********" << endl;
        cout << "* 0 - Sair                        *" << endl;
        cout << "* 1 - Gerar matriz                *" << endl;
        cout << "* 2 - Mostrar matriz              *" << endl;
        cout << "* 3 - Soma diagonais              *" << endl;
        cout << "* 4 - Matriz invertida            *" << endl;
        cout << "***********************************" << endl;
        cout << "Sua escolha: ";
        cin >> *pmenu;
        fflush(stdin);

        system("cls");

         if (*pmenu == 0)
        {
            cout << "\n\nPrograma encerrado com sucesso!\n\n";

        } else if (*pmenu == 1)
        {
           srand(time(NULL));
            do
            {
                cout << "Informe o número de linhas da matriz: ";
                cin >> *x;
                fflush(stdin);

                if (*x > 20 or *x <= 0)
                {
                    system ("cls");
                    cout << "Valor inválido! Tente novamente.";
                    getchar();
                    system("cls");
                }
            }while (*x > 20 or *x <= 0);

            matriz = new int[*x][5];

            for (*a = 0; *a < *x; (*a)++)
            {
                for (*b = 0; *b < 5; (*b)++)
                {
                    matriz[*a][*b] = rand() % 100;
                }
            }
            (*pc)++;

            cout << "\nMatriz gerada com sucesso!";
            getchar();

        } else if (*pmenu == 2)
        {
            if (*pc <= 0)
            {
                cout << "\nPrimeiro é necessário gerar a matriz!";
                getchar();

            } else

                mostrar (matriz, &x);
                getchar();

        } else if (*pmenu == 3)
        {
            if (*pc <= 0)
            {
                cout << "\nPrimeiro é necessário gerar a matriz!";
                getchar();

            } else
            {
                somar(matriz, x);
                getchar();
            }
        } else if (*pmenu == 4)
        {
            if (*pc <= 0)
            {
                cout << "\nPrimeiro é necessário gerar a matriz!";
                getchar();

            } else
            {

                inverter(matriz, x);
                getchar();
            }
        } else
        {
            cout << "\nOpção inválida! Tente novamente.";
            getchar();
        }
    } while (*pmenu != 0);
}

void mostrar (int (*matriz)[5], int **px)
{
    int *i = new int;
    int *j = new int;

    cout << "\nMatriz formada pelos elementos:\n\n";

    for (*i = 0; *i < **px; (*i)++)
    {
       for (*j = 0; *j < 5; (*j)++)
       {
           cout << matriz[*i][*j] << "\t";
       }
       cout << endl;
    }
    delete i;
    delete j;
}

void somar (int (*matriz)[5], int *px)
{
    int *i = new int;
    int *j = new int;
    int *sdp = new int(0);
    int *sds = new int(0);

    for (*i = 0; *i < *px; (*i)++)
    {
        for (*j = 0; *j < 5; (*j)++)
        {
            if(*i == *j)
            {
              *sdp += matriz[*i][*j];
            }
            if (*i + *j == (5 - 1))
                {
                    *sds += matriz[*i][*j];
                }
        }
    }

    delete i;
    delete j;

    cout << "Soma dos elementos na diagonal principal da matriz: " << *sdp << endl;
    cout << "Soma dos elementos na diagonal secundária da matriz: " << *sds << endl;
}

void inverter (int (*matriz)[5], int *px)
{
    int *i = new int;
    int *j = new int;

    cout << "\nMatriz invertida:\n\n";

    for (*i = *px - 1; *i >= 0; (*i)--)
    {
       for (*j = 0; *j < 5; (*j)++)
       {
           cout << matriz[*i][*j] << "\t";
       }
       cout << endl;
    }
}

