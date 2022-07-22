#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
	setlocale (LC_ALL , "Portuguese");

	srand(time(NULL));

	int n, DP=0, DS=0, soma=0, soma4=0, soma2=0, lin, col;

	cout << "Informe um número: ";
	cin >> n;

	int matriz[n][n];

	for (lin = 0; lin < n; lin++)
	{
	    for (col = 0; col < n; col++)
        {
            matriz[lin][col] = rand () % 10;

            soma+= matriz[lin][col];

            if (lin == col)
            {
                DP+= matriz[lin][col];
            }
            if (lin + col == n - 1)
            {
                    DS += matriz[lin][col];
            }
            if (lin == 3)
            {
                soma4+= matriz[lin][col];

            }

            if (col == 1)
            {
                soma2 += matriz[lin][col];
            }
            soma+= matriz[lin][col];
        }
	}

        getchar();
        system ("cls");

        cout << "Matriz formada pelos elementos: " << endl << endl;

        for(lin = 0; lin < n; lin++)
        {
            for (col = 0; col < n; col++)
            {
                cout << matriz[lin][col] << "\t";
            }
            cout << endl;
        }

        cout << "Soma dos elementos da quarta linha: " << soma4 << endl;
        cout << "Soma dos elementos da segunda coluna " <<soma2 << endl;
        cout << "Soma dos elementos da diagonal principal: " << DP << endl;
        cout << "Soma dos elementos da diagonal secundária: " << DS << endl;
        cout << "Soma dos elementos da matriz: " << soma << endl;
	}


