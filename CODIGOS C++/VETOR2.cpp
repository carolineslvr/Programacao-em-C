#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

void gerar (int *vet, int *c);
int somar(int *vet);
void mvalor (int *vet);
void comparar (int *vet);

main()
{
	setlocale (LC_ALL , "Portuguese");

	int vetor[10], cont = 0, menu = -1;

	do
    {
        system ("cls");

        cout << "********** MENU DE OPÇÕES *********" << endl;
        cout << "* 0 - Sair                        *" << endl;
        cout << "* 1 - Gerar valores               *" << endl;
        cout << "* 2 - Soma dos valores            *" << endl;
        cout << "* 3 - Maior e menor valor         *" << endl;
        cout << "* 4 - Verificar valor             *" << endl;
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
            gerar(vetor, &cont);
            getchar();

        } else if (menu == 2)
        {
            if (cont <= 0)
            {
                cout << "Primeiro é necessário gerar o vetor!";
                getchar();

            } else
            {
                cout << "Soma dos valores no vetor é igual a " << somar(vetor);
                getchar();
            }
        } else if (menu == 3)
        {
            if (cont <= 0)
            {
                cout << "Primeiro é necessário gerar o vetor!";
                getchar();

            } else
            {
                mvalor(vetor);
                getchar();
            }
        } else if (menu == 4)
        {
            if (cont <= 0)
            {
                cout << "Primeiro é necessário gerar o vetor!";
                getchar();

            } else
            {
                comparar(vetor);
                getchar();
            }
        } else
        {
            cout << "Opção inválida! Tente novamente.";
            getchar();
        }
    } while (menu != 0);
}

void gerar (int *vet, int *c)
{
   int i, *pi = &i;

   srand(time(NULL));

   cout << "Vetor gerado com sucesso e formado pelos elementos:\n\n";

   for (*pi = 0; *pi < 10; (*pi)++)
   {
       vet[*pi] = rand() % 36 + 25;

       cout << vet[*pi] << ", ";
   }

   (*c)++;
}

int somar(int *vet)
{
    int soma = 0, *psoma = &soma, j, *pj = &j;

    for (*pj = 0; *pj < 10; (*pj)++)
    {
        *psoma += vet[*pj];
    }

    return *psoma;
}

void mvalor (int *vet)
{
    int x, menor, maior, pmaior, pmenor, *px = &x;

    for (*px = 0; *px < 10; (*px)++)
    {
        if (*px == 0)
        {
            menor = vet[*px];
            pmenor = *px;

        } else if (vet[*px] < menor)
        {
            menor = vet[*px];
            pmenor = *px;
        }
    }

     for (*px = 0; *px < 10; (*px)++)
    {
        if (*px == 0)
        {
            maior = vet[*px];
            pmaior = *px;

        } else if (vet[*px] > maior)
        {
            maior = vet[*px];
            pmaior = *px;
        }
    }

    cout << "Maior valor do vetor é: " << maior << " e está localizado na posição " << pmaior;
    cout << "\nMenor valor do vetor é: " << menor << " e está localizado na posição " << pmenor;
}

void comparar (int *vet)
{
    int z, *pz = &z, num, *pn = &num, conta = 0;

    cout << "Informe um valor qualquer: ";
    cin >> *pn;
    fflush(stdin);

    for (*pz = 0; *pz < 10; (*pz)++)
    {
        if (*pn == vet[*pz])
        {

            cout << "Vetor " << vet[*pz] << " está incluido no vetor na posição " << *pz;

            return;
        } else
        {
            conta++;
        }
    }

    if (conta > 0)
    {
        cout << "Valor " << *pn << " não está incluído neste vetor!";
    }
}
