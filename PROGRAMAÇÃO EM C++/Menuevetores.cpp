#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
	setlocale (LC_ALL , "Portuguese");

	srand(time(NULL));

	int  i, x, aux, lin, col, maiores=-1, pares = -1, impares = -1, vetorX[10],vetorY[10], vetorZ[10], vetorW[10], vetorS[10], vetorU[20];

	cout << "Vetor X formado pelos elementos: " << endl;

	for (i = 0; i < 10; i++)
    {
        vetorX[i] = rand () % 51;

        cout << vetorX[i] << ", ";

        if (vetorX[i] % 2 == 0)
        {
            pares++;
            vetorW[pares] = vetorX[i];

        } else
        {
            impares++;
            vetorZ[impares] = vetorX[i];
        }

    }

    for (i = 0 ; i < 9; i++)
    {
        for (x = i + 1; x < 10; x++)
        {
            if (vetorX[i] > vetorX[x])
            {
                aux = vetorX[i];
                vetorX[i] = vetorX[x];
                vetorX[x] = aux;
            }
        }
    }
     cout << endl << endl << "Vetor X em ordem crescente: " << endl;

     for (i = 0; i < 10; i++)
     {
         cout << vetorX[i] << ", ";
     }

     cout << endl << endl << "Vetor Y formado pelos elementos: " << endl;

     for (i = 0; i < 10; i++)
     {
         vetorY[i] = rand () % 51;

         cout << vetorY[i] << ", ";

     }

     for (i = 0; i < 9; i++)
     {
         for (x = i + 1; x < 10; x++)
         {
             if (vetorY[i] < vetorY[x])
             {
                 aux = vetorY[i];
                 vetorY[i] = vetorY[x];
                 vetorY[x] = aux;

             }
         }
     }

     cout << endl << endl << "Vetor Y em ordem decrescente: " << endl;

     for (i = 0; i < 10; i++)
     {
         cout << vetorY[i] << ", ";
     }

     cout << endl << endl << "Números ímpares de X: " << endl;

     for (i = 0; i <= impares; i++)
     {
         cout << vetorZ[i] << ", ";
     }

     cout << endl << endl << "Números pares de X: " << endl;

    for (i = 0; i <= pares; i++)
    {
        cout << vetorW[i] << ", ";
    }

    cout << endl << endl << "União dos vetores X e Y: " << endl;

    for (i = 0; i < 10; i++)
    {
        vetorU[i] = vetorX[i];
    }
    for (i = 0; i < 10; i++)
    {
        vetorU [i + 10] = vetorY[i];
    }

    for (i = 0 ; i < 20; i++)
    {
        cout << vetorU[i] << ", ";

        if (vetorU[i] > 30)
        {
            maiores++;
            vetorS[maiores] = vetorU[i];
        }
    }
    cout << endl << endl << "Numeros dos Vetores X e Y maiores que 30:" << endl;
    for (i = 0; i <= maiores; i++)
    {
        cout << vetorS[i] << ", ";
    }



}
