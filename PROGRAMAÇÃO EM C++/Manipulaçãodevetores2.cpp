#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
	setlocale (LC_ALL , "Portuguese");

	int i;
	char vetor[20], aux;

	for (i = 0;  i < 20; i++)
    {
        cout << "Informe um caractere: ";
        cin >> vetor[i];
    }

    for (i = 0; i < 10; i++)
    {
        aux = vetor[i];
        vetor[i] = vetor[i + 10];
        vetor[i + 10] = aux;
    }

    system ("cls");

    cout << endl << "Vetor escolhido: " << endl;

    for (i = 0; i < 20; i++)
    {
        cout << vetor[i] << endl;
    }

    cout << endl << "Vetor após trocas: " << endl;

    for (i = 0; i < 20; i++)
    {
        cout << aux << endl;
    }
}
