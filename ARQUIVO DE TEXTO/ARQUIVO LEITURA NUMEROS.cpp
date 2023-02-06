#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>
#include<fstream>

using namespace std;

main()
{
	setlocale (LC_ALL , "Portuguese");

	ifstream leitura;
    char numeros[100];
    int vetor[100], cont = 0, soma = 0, maior, menor, impares = 0, pares = 0;


    leitura.open("teste20.txt", ios::in);

    if(leitura.is_open())
    {
       cout << "Dados no arquivo:\n\n";

        while(!leitura.eof())
        {
            leitura.getline(numeros, 100);
            cout << numeros << ", ";

            vetor[cont] = atoi(numeros);
            soma += vetor[cont];

            if (cont == 0)
            {
                maior = vetor[cont];

            } else if (vetor[cont] > maior)
            {
                maior = vetor[cont];
            }
             if (cont == 0)
             {
                 menor = vetor[cont];

             } else if (vetor[cont] < menor)
             {
                 menor = vetor[cont];
             }
             if (vetor[cont] % 2 == 0)
             {
                 pares++;

             } else
             {
                 impares++;
             }

             cont++;
        }

        getchar();
        cout << "\n\nMaior valor presente no arquivo: " << maior;
        getchar();
        cout << "\nMenor valor presente no arquivo: " << menor;
        getchar();
        cout << "\nMédia dos valores presentes no arquivo: " << (float)soma / (float)cont;
        getchar();
        cout << "\nO arquivo possui " << pares << " números pares e " << impares << " números ímpares.\n";

    } else
    {
        cout << "Erro ao abrir o arquivo!";
    }

}
