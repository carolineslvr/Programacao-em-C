#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

void leitura (int &num);
void ler (int &verificador);
int verificar (int n, int v, int &cont);

main()
{
	setlocale (LC_ALL , "Portuguese");

	int num, verificador, cont = 0;

	leitura(num);
	ler(verificador);
	verificar(num, verificador, cont);

	cout << "O número " << verificador << " aparece " << cont << " vezes." << endl;
}

void leitura(int &num)
{
    do
    {
        cout << "Informe um número inteiro maior que 10: ";
        cin >> num;
        fflush(stdin);

        if (num < 10)
        {
            system("cls");
            cout << "Número informado deve ser maior que 10! Digite novamente. ";
            getchar();
            system("cls");
        }
    }while(num < 10);
}

void ler( int &verificador)
{
    do
    {
        cout << "Informe um número inteiro entre 1 e 9: ";
        cin >> verificador;
        fflush(stdin);

        if (verificador < 0 && verificador > 9)
        {
            system("cls");
            cout << "Número informado deve estar entre 0 e 9! Digite novamente.";
            getchar();
            system("cls");
        }
    }while(verificador < 0 && verificador > 9);
}

int verificar (int n, int v, int &cont)
{
    if (n == 0)
    {
        return 0;

    } else
    {
        if (v ==(n % 10))
        {
            cont++;
        }

        n= n / 10;

        return verificar(n, v, cont);
    }
}
