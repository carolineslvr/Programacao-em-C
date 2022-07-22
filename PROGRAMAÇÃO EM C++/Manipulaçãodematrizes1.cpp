#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
	setlocale (LC_ALL , "Portuguese");

	int lin, col, centro, num;

	do{
        cout << "Informe um número ímpar: ";
        cin >> num;

        if ((num < 5 or num > 13) or (num % 2 == 0))
        {
        system("cls");
        cout << "Número informado deve ser ímpar, maior que 4 e menor que 14. Tente novamente." << endl;
        getchar();
        }

	} while ((num < 5 or num > 13) or (num % 2 == 0));

	int matriz[num][num];

	centro = num / 2;

	for (lin = 0; lin < num; lin++)
    {
        for (col = 0; col < num; col++)
        {
            if (lin == centro or col == centro)
            {
                matriz[lin][col] = 1;
            } else
            {
                matriz [lin][col] = 0;
            }
        }
    }
    for (lin = 0; lin < num; lin++)
    {
        for (col = 0; col < num; col++)
        {
            cout << matriz[lin][col] << "\t";
        }

        cout << endl;
    }
}
