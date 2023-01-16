#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

void leitura(int &num, int &gerou);
void primo (int &num, int &gerou);
int somar (int &num, int &gerou);

main()
{
	setlocale (LC_ALL , "Portuguese");

	int menu = 0, num, gerou = 0;
	do {
        system("cls");
        cout << ">>>>>>>>> MENU DE OPC��ES <<<<<<<<<\n\n";
        cout << "       0 - Sair              \n\n";
        cout << "       1 - Digite um valor   \n\n";
        cout << "       2 - Verifique se o n�mero � primo\n\n";
        cout << "       3 - Soma algarismos    \n\n";
        cin >> menu;
        fflush(stdin);

        system("cls");

        if (menu == 1)
        {
            leitura(num, gerou);
        }

        else if (menu == 2)
        {
            primo(num, gerou);
            getchar();

        } else if (menu == 3)
        {
            somar(num, gerou);
            getchar();


        } else if (menu == 0)
        {
            cout << "Programa encerrado com sucesso!\n";

        } else
        {
            cout << "Op��o inv�lida! Digite novamente.";
            getchar();
        }

	}while(menu != 0);
}

void leitura(int &num, int &gerou)
{
    cout << "Informe o n�mero desejado: ";
    cin >> num;
    fflush(stdin);
    gerou++;
}

void primo (int &num, int &gerou)
{
    int i, cont = 0;

    if(gerou == 0)
    {
        cout << "Primeiramente � necess�rio gerar o n�mero!";

    } else

    {

        if(num == 0 or num == 1)
        {
            cout << "Por defini��o, n�mero " << num <<  " n�o � primo!";

        } else
        {
            for(i = 2; i < num; i++)
            {
                if (num % i == 0)
                {
                    cont++;

                }
            }

            if (cont == 0)
            {
                cout << "N�mero " << num << " � primo!";

            } else
            {
                cout << "N�mero " << num << " n�o � primo!";
            }
        }
    }

}
int somar (int &num, int &gerou)
{
    int i, soma = 0, digito, numero;

    if (gerou == 0)
    {
        cout << "Primeiramente � necess�rio gerar o n�mero!";

    } else if (num < 0 or num > 999)
    {
        cout << "N�mero inv�lido para realiza��o desta fun��o!";

    } else

    {
        numero  = num;

        while (numero > 0)
        {
            digito = numero % 10;
            soma+= digito;
            numero = numero / 10;
        }

        cout << "Soma dos algarismos que comp�e o n�mero " << num << ": " << soma;
        return soma;
    }
}

