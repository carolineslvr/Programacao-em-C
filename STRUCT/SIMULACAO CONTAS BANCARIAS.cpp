#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

struct contas
{
    int numero;
    string nome;
    float saldo;
};

void cadastrar (contas vetor[], int &indice);
void mostrar (contas vetor[], int indice);
void deposito (contas vetor[], int indice);
void saque (contas vetor[], int indice);
void pix (contas vetor[], int indice);
main()
{
	setlocale (LC_ALL , "Portuguese");

	contas vetor[10];
	int menu = 0, indice = -1;

	do
    {
        system("cls");

        cout << ">>>MENU DE OPÇÕES<<<" << endl;
        cout << " 1 - Cadastrar    " << endl;
        cout << " 2 - Visualizar   " << endl;
        cout << " 3 - Depositar    " << endl;
        cout << " 4 - Sacar        " << endl;
        cout << " 5 - Pix          " << endl;
        cout << " 6 - Sair         " << endl;
        cout << "####################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        system("cls");

        if (menu == 1)
        {
            cadastrar(&vetor[0], indice);

        } else if (menu == 2)
        {
           if (indice < 0)
           {
               cout << "Nenhuma conta cadastrada!";
               getchar();

           } else
           {
               mostrar(vetor, indice);
               getchar();
           }
        } else if (menu == 3)
        {
            if (indice < 0)
           {
               cout << "Nenhuma conta cadastrada!";
               getchar();

           } else
           {
               deposito(&vetor[0], indice);
           }
        } else if (menu == 4)
        {
            if (indice < 0)
           {
               cout << "Nenhuma conta cadastrada!";
               getchar();

           } else
           {
               saque(&vetor[0], indice);
           }
        } else if (menu == 5)
        {
             if (indice < 0)
           {
               cout << "Nenhuma conta cadastrada!";
               getchar();

           } else
           {
               pix(&vetor[0], indice);
           }
        } else if (menu == 6)
        {
            cout << "Programa encerrado com sucesso!\n\n";

        } else
        {

            cout << "Opção digitada é inválida! Digite novamente.";
            getchar();

        }


    }while (menu != 6);
}

void cadastrar (contas vetor[], int &indice)
{
    int aux, igual, i, x;

    indice++;

        cout << "\nInforme o número da conta [" << indice << "]: ";
        cin >> aux;
        fflush(stdin);

       for (i = 0; i <= indice; i++)
       {
            if(indice == 0)
            {
                vetor[indice].numero = aux;

            } else
            {
                igual = 0;
                for (x = 0; x < indice; x++)
            {
                if (vetor[x].numero == aux)
                {
                    igual++;
                    break;
                }
            }
            if (igual == 0)
            {
                vetor[indice].numero = aux;

            } else
            {
                cout << "Atenção! Conta já cadastrada. Tente novamente.";
                getchar();
                indice--;

                return;
            }
        }
    }

    cout << "Informe o nome do cliente [" << indice << "]: ";
    getline(cin, vetor[indice].nome);
    fflush(stdin);

    cout << "Informe o saldo [" << indice << "]: ";
    cin >> vetor[indice].saldo;
    fflush(stdin);

    system("cls");
    cout << "Conta cadastrada com sucesso!";
    getchar();

}

void mostrar (contas vetor[], int indice)
{
    int i, num, cont = 0;

    cout << "Informe o número da conta: ";
    cin >> num;
    fflush(stdin);

    for (i = 0; i <= indice; i++)
    {
        if (num == vetor[i].numero)
        {
            system ("cls");
            cout << "Número da conta: " << vetor[i].numero << endl;
            cout << "Nome do cliente: " << vetor[i].nome << endl;
            cout << fixed;
            cout.precision(2);
            cout << "Saldo: R$" << vetor[i].saldo << endl;
            cout << "--------------------------------" << endl;

            cont--;

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

void deposito (contas vetor[], int indice)
{
    int num, i, cont = 0;
    float valor;

    cout << "Informe o número da conta: ";
    cin >> num;
    fflush(stdin);

    for (i = 0; i <= indice; i++)
    {
        if (num == vetor[i].numero)
        {
            cout << "Informe o valor a ser depositado: ";
            cin >> valor;
            fflush(stdin);

            vetor[i].saldo += valor;

            cout << "\nValor depositado com sucesso!";
            getchar();

            cont--;

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

void saque (contas vetor[], int indice)
{
    int num, i, cont = 0;
    float v;

    cout << "Informe o número da conta: ";
    cin >> num;
    fflush(stdin);

    for (i = 0; i <= indice; i++)
    {
        if (num == vetor[i].numero)
        {
            cout << "Informe o valor do saque: ";
            cin >> v;
            fflush(stdin);

            if (vetor[i].saldo < v)
            {
                cout << "Saldo indisponível!";
                getchar();
                return;

            } else
            {
                vetor[i].saldo -= v;
                cout << "\nSaque realizado com sucesso!";
                getchar();
            }

            cont--;

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

void pix (contas vetor[], int indice)
{
    int n1, n2, i, x, cont = 0, cont2 = 0;
    float val;

    cout << "Informe o valor do PIX: ";
    cin >> val;
    fflush(stdin);

    cout << "Informe o número da conta de origem: ";
    cin >> n1;
    fflush(stdin);

    for (i = 0; i <= indice; i++)
    {
        if (n1 == vetor[i].numero)
        {
            if (vetor[i].saldo < val)
            {
                cout << "Saldo indisponível!";
                getchar();
                return;

            } else
            {
                vetor[i].saldo -= val;
            }

            cont--;

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
    cout << "Informe o número da conta de destino: ";
    cin >> n2;
    fflush(stdin);

    for (i = 0; i <= indice; i++)
    {
        if (n2 == vetor[i].numero)
        {
            vetor[i].saldo += val;

            cout << "Pix realizado para " << vetor[i].nome << " com sucesso!";
            getchar();

            cont2--;
        } else
        {
            cont2++;
        }
    }
    if (cont2 > 0)
    {
        cout << "Conta de destino não encontrada!";
        getchar();
        return;
    }

}
