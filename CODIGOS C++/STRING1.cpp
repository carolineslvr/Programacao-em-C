#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

main()
{
	setlocale (LC_ALL , "Portuguese");

	int i;
	string texto;
	string texto2;
	string texto3;

    cout << "Informe o texto 1: ";
    getline(cin, texto);

    cout << "Informe o texto 2: ";
    getline(cin, texto2);

    cout << "Informe o texto 3: ";
    getline(cin, texto3);

    for (i = 0; i <= texto.size(); i++)
    {
        texto[i] = toupper(texto[i]);
    }
    for (i = 0; i <= texto2.size(); i++)
    {
        texto2[i] = toupper(texto2[i]);
    }
    for (i = 0; i <= texto3.size(); i++)
    {
        texto3[i] = toupper(texto3[i]);
    }


    if(texto.size() < texto2.size() && texto.size() < texto3.size())
    {
        if(texto2.size() < texto3.size())
            {
                cout << endl << "Menor texto: " << texto << endl;
                cout << "Texto médio: " << texto2 << endl;
                cout << "Maior texto: " << texto3 << endl;

            } else if (texto3.size() < texto2.size())
            {
                cout << endl << "Menor texto: " << texto << endl;
                cout << "Texto médio: " << texto3 << endl;
                cout << "Maior texto: " << texto2 << endl;
            }
    } else if (texto2.size() < texto.size() && texto2.size() < texto3.size())
    {
        if (texto.size() < texto3.size())
        {
                cout << endl << "Menor texto: " << texto2 << endl;
                cout << "Texto médio: " << texto << endl;
                cout << "Maior texto: " << texto3 << endl;

        } else if (texto3.size() < texto.size())
        {
                cout << endl << "Menor texto: " << texto2 << endl;
                cout << "Texto médio: " << texto3 << endl;
                cout << "Maior texto: " << texto << endl;
        }
    } else if (texto3.size() < texto.size() && texto3.size() < texto2.size())
    {
        if (texto.size() < texto2.size())
        {
                cout << endl << "Menor texto: " << texto3 << endl;
                cout << "Texto médio: " << texto << endl;
                cout << "Maior texto: " << texto2 << endl;

        } else if (texto2.size() < texto.size())
        {
                cout << endl << "Menor texto: " << texto3 << endl;
                cout << "Texto médio: " << texto2 << endl;
                cout << "Maior texto: " << texto << endl;
        }
    }


}
