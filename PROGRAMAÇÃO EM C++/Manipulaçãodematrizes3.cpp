#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
	setlocale (LC_ALL , "Portuguese");
	srand(time(NULL));

	int lin, col, aux, maior, maior2 = 0, num, num2;


	cout << "Informe um número: ";
	cin >> num;
	fflush(stdin);


	int matriz[num][num];

	for (lin = 0; lin < num; lin++)
    {
        for (col = 0; col < num; col++)
        {
            matriz[lin][col] = rand() % 51 + 20;

            if (lin == 0 && col == 0)
            {
                maior = matriz[lin][col];

            } else if (matriz[lin][col] > maior)
            {
                maior = matriz[lin][col];
            }

        }
    }

    cout << "Matriz formada pelos elementos: " << endl;

    for (lin = 0; lin < num; lin++)
    {
        for (col = 0; col < num; col++)
        {
         cout << matriz [lin][col] << "\t";
        }
        cout << endl;
    }



    cout << endl << "Maior elemento da matriz: " << maior << endl;

     for (lin = 0; lin < num; lin++)
    {
        for (col = 0; col < num; col++)
        {
            if (lin == col)
            {
                matriz[lin][col] = maior;
            }
            cout << matriz [lin][col] << "\t";
        }
        cout << endl;
    }



     do{
        cout << "Informe um número maior que 20 e menor que 70:";
        cin >> num2;

        if (num2 <= 20 or num2 >= 70)
        {
            cout << "Número digitado é inválido. Tente novamente.";
            getchar();
        }
     } while (num2 <= 20 or num2 >= 70);

     for (lin = 0; lin < num; lin++)
    {
        for (col = 0; col < num; col++)
        {
            if (matriz[lin][col] > num2)
            {
                maior2++;
            }
        }
    }
        cout << fixed;
        cout.precision(2);

    cout << "Quantidade de elementos maiores que o número " << num2 << ": " << maior2;
    cout << endl << "Percentual de elementos maiores que o número " << num2 << ": " << ((float)maior2 / ((float)num *(float)num)) * 100.00 << "%" << endl;



         for (col = 0; col < num; col++)
        {
           aux = matriz[0][col];
           matriz[0][col] = matriz[num - 1][col];
           matriz[num - 1][col] = aux;
        }

    cout << endl << "Matriz com elementos trocados: " << endl;

    for (lin = 0; lin < num; lin++)
    {
        for (col = 0; col < num; col++)
        {
         cout << matriz [lin][col] << "\t";
        }
        cout << endl;
    }
}
