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

	ifstream leitura ("teste17.txt", ios::in);

	char numeros[200];
	int cont = 0;
	float soma = 0, vetor[200], maior, menor;

	if (leitura.is_open())
    {
        cout << "\nConteúdo no arquivo:\n\n";

        while(!leitura.eof())
        {
            leitura.getline(numeros, 200, ';');
            cout << numeros << endl;


            vetor[cont] = atof(numeros);

            soma+= vetor[cont];

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

            cont++;
       }

        getchar();
        cout << fixed;
        cout.precision(2);
        cout << "\nSoma dos números no arquivo: " << soma;
        getchar();
        cout << "\nMédia dos números do arquivo: " << soma / (float)cont;
        getchar();
        cout << "\nMaior número presente no arquivo: " << maior;
        getchar();
        cout << "\nMenor número presente no arquivo: " << menor;

    } else
    {
        cout << "\nErro ao abrir o arquivo!\n";
    }


}
