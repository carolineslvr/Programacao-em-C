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
        cout << ">>>>>>>>> MENU DE OPCÇÕES <<<<<<<<<\n\n";
        cout << "       0 - Sair              \n\n";
        cout << "       1 - Digite um valor   \n\n";
        cout << "       2 - Verifique se o número é primo\n\n";
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
            cout << "Opção inválida! Digite novamente.";
            getchar();
        }

	}while(menu != 0);
}

void leitura(int &num, int &gerou)
{
    cout << "Informe o número desejado: ";
    cin >> num;
    fflush(stdin);
    gerou++;
}

void primo (int &num, int &gerou)
{
    int i, cont = 0;

    if(gerou == 0)
    {
        cout << "Primeiramente é necessário gerar o número!";

    } else

    {

        if(num == 0 or num == 1)
        {
            cout << "Por definição, número " << num <<  " não é primo!";

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
                cout << "Número " << num << " é primo!";

            } else
            {
                cout << "Número " << num << " não é primo!";
            }
        }
    }

}
int somar (int &num, int &gerou)
{
    int i, soma = 0, digito, numero;

    if (gerou == 0)
    {
        cout << "Primeiramente é necessário gerar o número!";

    } else if (num < 0 or num > 999)
    {
        cout << "Número inválido para realização desta função!";

    } else

    {
        numero  = num;

        while (numero > 0)
        {
            digito = numero % 10;
            soma+= digito;
            numero = numero / 10;
        }

        cout << "Soma dos algarismos que compõe o número " << num << ": " << soma;
        return soma;
    }
}

