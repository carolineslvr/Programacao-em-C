#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

struct estoque
{
    int codigo;
    char nome[100];
    float preco;
    int quant;
};

void carregar (estoque p[], int &i);
void gravar (estoque p[], int &i);
void ler (estoque p[], int &i, int &ok);
void mostra (estoque p[], int i);
void vender (estoque p[], int i);
void zerado (estoque p[], int i);
void consultar (estoque p[], int i);

main()
{


    estoque prod[20];
    int menu, indice = -1, ok = 0;
    carregar(prod, indice);

    do
    {
        system("cls");
        cout << "****MENU DE OPCOES:****" << endl;
        cout << "*0 - Sair             *" << endl;
        cout << "*1 - Incluir produto  *" << endl;
        cout << "*2 - Vender produto   *" << endl;
        cout << "*3 - Estoque zerado   *" << endl;
        cout << "*4 - Consultar produto*" << endl;
        cout << "*5 - Mostrar produtos *" << endl;
        cout << "***********************" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
        case 0:
            gravar(prod, indice);
            cout << "DADOS ATUALIZADOS NO ARQUIVO TEXTO!";
            cout << "PROGRAMA FINALIZADO!";
            getchar();
            break;
        case 1:
            system("cls");
            ler(prod, indice, ok);
            if (ok > 0)
                gravar (prod, indice);
            break;
        case 2:
            system("cls");
            if(indice < 0)
                cout << "NAO EXISTE NENHUM CADASTRO ATUALMENTE!";
            else
                vender(prod, indice);
            getchar();
            break;
        case 3:
            system ("cls");
            if(indice < 0)
                cout << "NAO EXISTE NENHUM CADASTRO ATUALMENTE!";
            else
                zerado (prod, indice);
            getchar();
            break;
        case 4:
            system ("cls");
            if(indice < 0)
                cout << "NAO EXISTE NENHUM CADASTRO ATUALMENTE!";
            else
                consultar(prod, indice);
            getchar();
            break;
        case 5:
            system ("cls");
            if(indice < 0)
                cout << "NAO EXISTE NENHUM CADASTRO ATUALMENTE!";
            else
                mostra(prod, indice);
            getchar();
            break;
        default:
            cout << "Opcao invalida tente novamente!";
            getchar();
        };
    } while(menu != 0);
}

void carregar (estoque p[], int &i)
{
    char aux[100];
    int cont = 0;
    ifstream ler("produtos.txt");
    if(ler.is_open())
    {
        ler.getline(aux, 100, '#');
        while(!ler.fail())
        {
            if(cont == 0)
               i++;
            cont++;
            if(cont == 1)
            {
               p[i].codigo = atoi(aux);

            }else if(cont == 2)
            {
                strcpy(p[i].nome, aux);

            } else if (cont == 3)
            {
                p[i].preco = atof(aux);

            } else if (cont == 4)
            {
                p[i].quant = atoi(aux);
                cont = 0;
            }

            ler.getline(aux, 100, '#');
        }
    }
    ler.close();
}

void gravar (estoque p[], int &i)
{
    ofstream escreve;
    escreve.open("produtos.txt", ios::out);
    if(escreve.is_open())
    {
        for(int j = 0; j <= i; j++)
        {
            escreve << p[j].codigo << "#" << p[j].nome << "#" << p[j].preco << "#" << p[j].quant << "#";
        }
    }
    escreve.close();
}

void ler (estoque p[], int &i, int &ok)
{
    int aux, j, x, igual;
    i++;
    cout << "Informe o codigo: ";
    cin >> aux;
    fflush(stdin);

     for (j = 0; j <= i; j++)
       {
            if(i == 0)
            {
                p[i].codigo = aux;

            } else
            {
                igual = 0;
                for (x = 0; x < i; x++)
            {
                if (p[x].codigo == aux)
                {
                    igual++;
                    break;
                }
            }
            if (igual == 0)
            {
                p[i].codigo = aux;

            } else
            {
                cout << "Atencao! Conta ja cadastrada. Tente novamente.";
                getchar();
                i--;
                ok--;
                return;
            }
        }
    }

    cout << "Informe o nome do produto: ";
    gets(p[i].nome);
    fflush(stdin);

    cout << "Informe o preco do produto: ";
    cin >> p[i].preco;
    fflush(stdin);

    cout << "Informe a quantidade no estoque: ";
    cin >> p[i].quant;

    cout << "\nProdutos gravados com sucesso!";
    ok = 1;
}

void mostra (estoque p[], int i)
{
    cout << "Dados informados: " << endl;
    for(int j = 0; j <= i; j++)
    {
        cout << "Codigo: " << p[j].codigo << endl;
        cout << "Nome: " << p[j].nome << endl;
        cout << "Preco: " << p[j].preco << endl;
        cout << "Quantidade: " << p[j].quant << endl;
        cout << "..................................." << endl;
    }
}

void vender (estoque p[], int i)
{
   int j, x, q, cont = 0;

    cout << "Informe o codigo do produto que deseja vender: ";
    cin >> x;
    fflush(stdin);

    for (j = 0; j <= i; j++)
    {
        if (x == p[j].codigo)
        {
            cout << "Informe a quantidade de itens que deseja vender: ";
            cin >> q;
            fflush(stdin);

            if (q > p[j].quant)
            {
                cout << "\nQuantidade indisponivel!";
                getchar();
                return;

            } else
            {
                p[j].quant -= q;
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

void zerado (estoque p[], int i)
{
    int j;
    cout << "Produtos com estoque zerado:\n\n";

    for (j = 0; j <= i; j++)
    {
        if(p[j].quant == 0)
        {
            cout << "Codigo: " << p[j].codigo << endl;
            cout << "Nome: " << p[j].nome << endl;
            cout << "Preco: " << p[j].preco << endl;
            cout << "Quantidade: " << p[j].quant << endl;
            cout << "..................................." << endl;
        }
    }
}

void consultar (estoque p[], int i)
{
    int j, num, cont = 0;

    cout << "Informe o código do produto: ";
    cin >> num;
    fflush(stdin);

    for (j = 0; j <= i; j++)
    {
        if (num == p[j].codigo)
        {
            system("cls");
            cout << "Codigo: " << p[j].codigo << endl;
            cout << "Nome: " << p[j].nome << endl;
            cout << "Preco: " << p[j].preco << endl;
            cout << "Quantidade: " << p[j].quant << endl;
            cout << "..................................." << endl;

            cont--;
            return;

        } else
        {
            cont++;
        }
    }
    if (cont > 0)
    {
        cout << "Conta não encontrada! Tente novamente!";
        getchar();

        return;
    }
}

