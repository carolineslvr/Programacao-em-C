#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

struct estoque
{
    int codigo;
    string nome;
    string unidade;
    float valor;
    int quantidade;
};

void cadastrar (int *in, estoque *prod);
void mostrar (int *in, estoque *prod);
void consultar (int *in, estoque *prod);
void vender (int *in, estoque *prod);


main()
{
	setlocale (LC_ALL , "Portuguese");

	estoque produto[50];
	int menu = -1, indice = -1;

	do
    {
        system ("cls");

        cout << "********** MENU DE OPÇÕES *********" << endl;
        cout << "* 0 - Sair                        *" << endl;
        cout << "* 1 - Cadastrar produto           *" << endl;
        cout << "* 2 - Listar produtos cadastrados *" << endl;
        cout << "* 3 - Consultar produto           *" << endl;
        cout << "* 4 - Vender produto              *" << endl;
        cout << "***********************************" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        system("cls");

        if (menu == 0)
        {
            cout << "\n\nPrograma encerrado com sucesso!\n\n";

        } else if (menu == 1)
        {
            cadastrar(&indice, produto);

        } else if (menu == 2)
        {
            if (indice < 0)
            {
                cout << "Nenhum produto cadastrado!";
                getchar();

            } else
            {
                mostrar(&indice, produto);
                getchar();
            }
        } else if (menu == 3)
        {
            if (indice < 0)
            {
               cout << "Nenhum produto cadastrado!";
               getchar();

            } else
            {
                consultar(&indice, produto);
                getchar();
            }
        } else if (menu == 4)
            {
                if (indice < 0)
                {
                    cout << "Nenhum produto cadastrado!";
                    getchar();

                } else
                {
                    vender(&indice, produto);
                    getchar();
                }
            } else
            {
                cout << "Opção escolhida é inválida! Por favor, tente novamente.";
                getchar();
            }
    }while (menu != 0);
}


void cadastrar (int *in, estoque *prod)
{
    (*in)++;

    cout << "Informe o código do produto " << *in << ": ";
    cin >> prod[*in].codigo;
    fflush(stdin);

    cout << "Informe o nome do produto " << *in << ": ";
    getline(cin, prod[*in].nome);
    fflush(stdin);

    cout << "Informe a unidade de medida do produto " << *in << ": ";
    getline(cin, prod[*in].unidade);
    fflush(stdin);

    cout << "Informe o valor do produto " << *in << ": ";
    cin >> prod[*in].valor;
    fflush(stdin);

    cout << "Informe a quantidade em estoque do produto " << *in << ": ";
    cin >> prod[*in].quantidade;
    fflush(stdin);

    system("cls");
    cout << "\nProduto cadastrado com sucesso!";
    getchar();
}

void mostrar (int *in, estoque *prod)
{
    int i, *pi = &i;

    cout << "ITENS CADASTRADOS:\n\n";

    for (*pi = 0; *pi <= *in; (*pi)++)
    {
        cout << "Código do produto: " << prod[*pi].codigo << endl;
        cout << "Nome do produto: " << prod[*pi].nome << endl;
        cout << "Unidade de medida: " << prod[*pi].unidade << endl;
        cout << "Quantidade em estoque: " << prod[*pi].quantidade << endl;
        cout << fixed;
        cout.precision(2);
        cout << "Valor do produto R$: " << prod[*pi].valor << endl;
        cout << "\n-----------------------------------------------------\n";
    }
}

void consultar (int *in, estoque *prod)
{
    int j, *pj = &j, n, cont = 0;

    cout << "Informe o código do produto que deseja visualizar: ";
    cin >> n;
    fflush(stdin);

    for (*pj = 0; *pj <= *in; (*pj)++)
    {
        if (n == prod[*pj].codigo)
        {
            system("cls");
            cout << "Código do produto: " << prod[*pj].codigo << endl;
            cout << "Nome do produto: " << prod[*pj].nome << endl;
            cout << "Unidade de medida: " << prod[*pj].unidade << endl;
            cout << "Quantidade em estoque: " << prod[*pj].quantidade << endl;
            cout << fixed;
            cout.precision(2);
            cout << "Valor do produto R$: " << prod[*pj].valor << endl;
            cout << "\n-----------------------------------------------------\n";

            return;

        } else
        {
            cont ++;
        }
    }
    if (cont > 0)
    {
        cout << "Produto não encontrado! Tente novamente.";
        getchar();

        return;
    }
}

void vender (int *in, estoque *prod)
{
    int num, x, *px = &x, quant, cont = 0;

    cout << "Informe o código do produto que deseja vender: ";
    cin >> num;
    fflush (stdin);

    for (*px = 0; *px <= *in; (*px)++)
    {
        if (num == prod[*px].codigo)
        {
            cout << "Informe a quatidade de itens que deseja vender: ";
            cin >> quant;
            fflush(stdin);

            if (prod[*px].quantidade < quant)
            {
                cout << "Estoque insuficiente para realização da venda!";
                getchar();
                return;

            } else
            {
                prod[*px].quantidade -= quant;
                cout << "\nVenda realizada com sucesso!";
                getchar();

            }
            cont--;
            return;

        } else
        {
            cont++;
        }
    }

    if (cont > 0)
    {
        cout << "Produto não encontrado! Tente novamente!";
        getchar();

        return;
    }
}

