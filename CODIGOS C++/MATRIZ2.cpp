#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

void gerar (int matriz[][5]);
void mostrar (int matriz[][5]);
void transposta (int matriz[][5]);
void maiormenor (int matriz[][5]);
float fmedia (int matriz[][5]);



main()
{
	setlocale (LC_ALL , "Portuguese");

	int matriz[3][5];

	gerar(matriz);
	mostrar(matriz);
	getchar();
	transposta(matriz);
	getchar();
	maiormenor(matriz);
	getchar();


	cout << fixed;
	cout.precision(2);
	cout << "\nMédia dos elementos da matriz: " << fmedia(matriz) << endl << endl;

}

void gerar (int matriz[][5])
{
    srand(time(NULL));
    int lin, col, i, j , cont = 0;

    for (lin = 0; lin < 3; lin++)
    {
        for (col = 0; col < 5; col++)
        {
            matriz[lin][col] = rand() % 51;

            if(matriz[lin][col] % 2 != 0)
            {
                col--;
            }
        }
    }
}

void mostrar (int matriz[][5])
{
    int lin, col;

    cout << "Matriz formada pelos elementos:\n";

    for (lin = 0; lin < 3; lin++)
    {
        for (col = 0; col < 5; col++)
        {
            cout << matriz[lin][col] << "\t";
        }

        cout << endl;
    }
}

void transposta (int matriz[][5])
{
    int lin, col, matrizT[5][3];

     for (lin = 0; lin < 3; lin++)
    {
        for (col = 0; col < 5; col++)
        {
            matrizT[col][lin] = matriz[lin][col];
        }

        cout << endl;
    }

    cout << "Matriz transposta:\n\n";

    for (lin = 0 ; lin < 5; lin++)
    {
        for (col = 0; col < 3; col++)
        {
            cout << matrizT[lin][col] << "\t";
        }

        cout << endl;
    }
}

void maiormenor (int matriz[][5])
{
    int lin, col, maior, menor;

    for (lin = 0; lin < 3; lin++)
    {
        for (col = 0; col < 5; col++)
        {
            if (lin == 0 && col == 0)
            {
                maior = matriz[lin][col];

            } else if (matriz[lin][col] > maior)
            {
                maior = matriz[lin][col];
            }
        }

    }
    for (lin = 0; lin < 3; lin++)
    {
        for (col = 0; col < 5; col++)
        {
            if (lin == 0 && col == 0)
            {
                menor = matriz[lin][col];

            } else if (matriz[lin][col] < menor)
            {
                menor = matriz[lin][col];
            }
        }

    }

    cout << "\nMaior elemento da matriz: " << maior << endl;
    cout << "\nMenor elemento da matriz: " << menor << endl;
}

float fmedia (int matriz[][5])
{
    int lin, col;
    float soma = 0, media;


    for (lin = 0; lin < 3; lin++)
    {
        for (col = 0; col < 5; col++)
        {
            soma+= matriz[lin][col];
        }
    }

    media = soma / 15;

    return media;

}
