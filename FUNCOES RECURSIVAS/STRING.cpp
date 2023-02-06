#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

void inverso(string texto, int j);

main()
{
	setlocale (LC_ALL , "Portuguese");

	string texto;
	int i, j, caracteres = 0;

	do
    {
        cout << "Informe o texto desejado: ";
        getline(cin, texto);
        fflush(stdin);

        for (i = 0; i < texto.size(); i++)
        {
            if((!isalnum(texto[i])) && (!isspace(texto[i])))
        {
            caracteres++;

        } else
        {
            caracteres--;
        }
        }

        if (caracteres > 0)
        {

                system("cls");
                cout << "Entrada inválida! Por favor digite um novo texto, contendo apenas letras e números.";
                cout << caracteres;
                getchar();
                system("cls");
        }

    }while(caracteres > 0);

    j = texto.size();

    inverso(texto, j);

}

void inverso(string texto, int j)
{

    if (j == -1)
    {
        return;

    } else
    {
       cout << texto[j];

       inverso(texto, j-1);
    }
}
