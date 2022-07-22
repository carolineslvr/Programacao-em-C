#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
	setlocale (LC_ALL , "Portuguese");
	srand(time(NULL));

	int lin, col, minimax, maior, posicaol, posicaoc, menor, matriz[10][10];

	for (lin = 0; lin < 10; lin++)
    {
        for (col = 0; col < 10; col++)
        {
            matriz[lin][col] = rand() % 1001;

            if (lin == 0 && col == 0)
            {
                maior = matriz[lin][col];
                posicaol = lin;
                posicaoc = col;

            } else if (matriz[lin][col] > maior)
            {
                maior = matriz[lin][col];
                posicaol = lin;
                posicaoc = col;
            }


            cout << matriz[lin][col] << "\t";
        }
        cout << endl;
    }

    minimax = matriz[posicaol][0];

    for(int col = 0; col < 10; col++)
    {
        if(matriz[posicaol][col] < minimax)
        {
        minimax = matriz[posicaol][col];
        }
    }
    cout << endl << endl << "Maior número da matriz: " << maior << ". Encontrado na linha " << posicaol << " e na coluna " << posicaoc;
    cout << endl << "Minimax: " << minimax;
}
