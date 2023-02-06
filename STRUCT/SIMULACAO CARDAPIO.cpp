#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

struct prato
{
    string ingredientes;
    string preparo;
    float calorias;
};
struct cardapio
{
    int codigo;
    string nome;
    prato x;
    float valor;
};

void incluir (cardapio itens[], int &ind);
void mostrar (cardapio itens[], int &ind);
void detalhar (cardapio itens[], int &ind);
void maiscaro (cardapio itens[], int &ind);
void menoscalorico (cardapio itens[], int &ind);

main()
{
	setlocale (LC_ALL , "Portuguese");

    cardapio itens[20];

    int menu = -1, indice = -1;

	do
    {
        system("cls");

        cout << "********** MENU DE OP��ES *********" << endl;
        cout << "* 0 - Sair                        *" << endl;
        cout << "* 1 - Incluir                     *" << endl;
        cout << "* 2 - Mostrar card�dio            *" << endl;
        cout << "* 3 - Detalhar card�pio           *" << endl;
        cout << "* 4 - Card�pio mais caro          *" << endl;
        cout << "* 5 - Card�pio com menos calorias *" << endl;
        cout << "***********************************" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        system("cls");

        if (menu == 0)
        {
            cout << "Programa encerrado com sucesso!\n\n";

        } else if (menu == 1)
        {
            incluir(&itens[0], indice);

            system("cls");
            cout << "Prato inclu�do com sucesso!";
            getchar();

        } else if (menu == 2)
        {
            if (indice < 0)
            {
                cout << "Nenhum prato inclu�do no card�pio!";
                getchar();

            } else
            {
                mostrar(&itens[0], indice);
                getchar();
            }


        } else if (menu == 3)
        {
            if (indice < 0)
            {
                cout << "Nenhum prato inclu�do no card�pio!";
                getchar();

            } else
            {
                detalhar(&itens[0], indice);
                getchar();
            }

        } else if (menu == 4)
        {
             if (indice < 0)
            {
                cout << "Nenhum prato inclu�do no card�pio!";
                getchar();

            } else
            {
                maiscaro(&itens[0], indice);
                getchar();
            }
        } else if (menu == 5)
        {
             if (indice < 0)
            {
                cout << "Nenhum prato inclu�do no card�pio!";
                getchar();

            } else
            {
                menoscalorico(&itens[0], indice);
                getchar();
            }
        }

    } while (menu !=0);
}

void incluir (cardapio itens[], int &ind)
{
    ind++;
    int i;

    cout << "Informe o c�digo do produto " << ind << ": ";
    cin >> itens[ind].codigo;
    fflush(stdin);

    cout << "Informe o nome do prato " << ind << ": ";
    cin >> itens[ind].nome;
    fflush(stdin);

    cout << "Informe os ingredientes do prato " << ind << ": ";
    getline(cin, itens[ind].x.ingredientes);
    fflush(stdin);

    cout << "Informe o modo de preparo do prato " << ind << ": ";
    getline(cin, itens[ind].x.preparo);
    fflush(stdin);

    cout << "Informe a quantidade de calorias do prato " << ind << ": ";
    cin >> itens[ind].x.calorias;
    fflush(stdin);

    cout << "Informe o valor do prato " << ind << ": ";
    cin >> itens[ind].valor;
    fflush(stdin);
}

void mostrar (cardapio itens[], int &ind)
{
    int i;

    cout << ">>> CARD�PIO: <<<" << endl << endl;

    for (int i = 0; i <=ind; i++)
    {
        cout << "C�digo: " << itens[i].codigo << endl;
        cout << "Nome: " << itens[i].nome << endl;
        cout << fixed;
        cout.precision(2);
        cout << "Valor: R$" << itens[i].valor << endl;
        cout << "\n--------------------------------\n";
    }
}

void detalhar (cardapio itens[], int &ind)
{
    int i, num, cont = 0;

    cout << "Informe o c�digo do prato que deseja detalhar: ";
    cin >> num;
    fflush(stdin);

    for (i = 0; i <= ind; i++)
    {
        if (num == itens[i].codigo)
        {
            system ("cls");
            cout << "Nome do prato: " << itens[i].nome << endl << endl;
            cout << "C�digo: " << itens[i].codigo << endl;
            cout << "Ingredientes: " << itens[i].x.ingredientes << endl;
            cout << "Preparo: " << itens[i].x.preparo << endl;
            cout << "Calorias: " << itens[i].x.calorias << endl;
            cout << fixed;
            cout.precision(2);
            cout << "Valor: R$" << itens[i].valor << endl;

            cont--;

        } else
        {
            cont++;
        }
    }
    if (cont > 0)
    {
        cout << "Prato n�o encontrado! Tente novamente.";
        getchar();

        return;
    }
}

void maiscaro (cardapio itens[], int &ind)
{
    int i, caro;

    for (i = 0; i <= ind; i++)
    {
        if (i == 0)
        {
            caro = i;

        } else if (itens[i].valor > itens[caro].valor)
        {
            caro = i;
        }
    }

    cout << "Prato mais caro:\n";
    cout << itens[caro].nome << ".\n";
    cout << "C�digo: " << itens[caro].codigo << endl;
    cout << fixed;
    cout.precision(2);
    cout << "Valor: R$" << itens[caro].valor;
}
void menoscalorico (cardapio itens[], int &ind)
{
    int i, menos;

    for (i = 0; i <= ind; i++)
    {
        if (i == 0)
        {
            menos = i;

        } else if (itens[i].valor > itens[menos].valor)
        {
            menos = i;
        }
    }

    cout << "Prato mais caro:\n";
    cout << itens[menos].nome << ".\n";
    cout << "C�digo: " << itens[menos].codigo << endl;
    cout << "Quantidade de calorias: " << itens[menos].x.calorias << endl;
    cout << fixed;
    cout.precision(2);
    cout << "Valor: R$" << itens[menos].valor;
}

