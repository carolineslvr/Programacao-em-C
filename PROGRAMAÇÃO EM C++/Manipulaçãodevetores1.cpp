#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
	setlocale (LC_ALL , "Portuguese");
	srand(time(NULL));

	int i, x, soma = 0, media, aux, menores = -1, vetorV[15],vetorW[15];

	cout << "Vetor V formado pelos elementos: " << endl;

	for (i = 0; i < 15; i++)
    {
        vetorV [i] = rand() % 20;

        soma+= vetorV[i];

        cout << vetorV[i] << ", ";
    }

    media = soma / 15;

    cout << endl << "Média dos elementos presentes no vetor: " << media << endl;

    for (i = 0; i < 15; i++)
    {
        if (vetorV[i] <= media)
        {
            menores++;

            vetorW[menores] = vetorV[i];
        }
    }

    cout << endl << "Vetor W formado pelos elementos: " << endl;

    for (i = 0; i <= menores; i++)
    {
        cout << vetorW[i] << ", ";
    }

    for (i = 0; i < menores; i++)
    {
        for (x = i + 1; x <= menores; x++)
        {
            if(vetorW[i] > vetorW[x])
            {
                aux = vetorW[i];
                vetorW[i] = vetorW[x];
                vetorW[x] = aux;
            }
        }
    }

    cout << endl << "Vetor W em ordem crescente: " << endl;

     for (i = 0; i <= menores; i++)
        {
            cout << vetorW[i] << ", ";
        }

}
